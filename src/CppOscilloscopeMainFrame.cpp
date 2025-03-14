#include "CppOscilloscopeMainFrame.h"
#include <wx/dcbuffer.h>
#include <wx/filedlg.h>
#include <iostream>
#include "DataLoader.h"
#include "Plotter.h"
#include "wx/wfstream.h"

CppOscilloscopeMainFrame::CppOscilloscopeMainFrame(wxWindow* parent)
    : MainFrame(parent),
      _config{std::make_shared<Config>(OperatingModeRadioBox->GetSelection(), DrawStyleRadioBox->GetSelection(), ShowGridCheckbox->IsChecked())} {
  DrawPanel->SetBackgroundStyle(wxBG_STYLE_PAINT);
  wxImage::AddHandler(new wxJPEGHandler);
}

void CppOscilloscopeMainFrame::DrawPanelOnPaint(wxPaintEvent& event) {
  wxAutoBufferedPaintDC dc{DrawPanel};

  // no-op if we haven't loaded the data yet
  if (_currentData.getDataPoints().empty()) {
    return;
  }

  wxBitmap bitmap{DrawPanel->GetSize()};
  wxMemoryDC memDC{bitmap};

  Plotter plotter{_config};
  plotter.draw(memDC, _currentData, _previousData, _historicData);

  memDC.SelectObject(wxNullBitmap);
  dc.DrawBitmap(bitmap, {0, 0});

  _output_image = bitmap.ConvertToImage();
}

void CppOscilloscopeMainFrame::DrawPanelOnUpdateUI(wxUpdateUIEvent& event) {
  DrawPanel->Refresh();
}

void CppOscilloscopeMainFrame::LoadFileButtonOnButtonClick(wxCommandEvent& event) {
  wxFileDialog openDataDialog{this, "Open the data file", "", "dane.txt", "TXT files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST};

  if (openDataDialog.ShowModal() == wxID_CANCEL) {
    return;
  }

  _config->setFilepath(openDataDialog.GetPath().ToStdString());
  loadData(_config->getFilepath());

  RefreshTimer.Start(100);
}

void CppOscilloscopeMainFrame::OperatingModeRadioBoxOnRadioBox(wxCommandEvent& event) {
  OperatingMode mode = static_cast<OperatingMode>(OperatingModeRadioBox->GetSelection());
  _config->setOperatingMode(mode);
  DrawPanel->Refresh();
  updateStats();
}

void CppOscilloscopeMainFrame::DrawStyleRadioBoxOnRadioBox(wxCommandEvent& event) {
  DrawStyle style = static_cast<DrawStyle>(DrawStyleRadioBox->GetSelection());
  _config->setDrawStyle(style);
  DrawPanel->Refresh();
}

void CppOscilloscopeMainFrame::ShowGridCheckboxOnCheckBox(wxCommandEvent& event) {
  _config->setShowGrid(ShowGridCheckbox->IsChecked());
  DrawPanel->Refresh();
}

void CppOscilloscopeMainFrame::BitmapSaveButtonOnButtonClick(wxCommandEvent& event) {
  wxFileDialog saveImageDialog(this, _("Save the image"), "", "", "JPEG file (*.jpeg)|*.jpeg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

  if (saveImageDialog.ShowModal() == wxID_CANCEL) {
    return;
  }

  wxFileOutputStream output_stream(saveImageDialog.GetPath());
  if (!output_stream.IsOk()) {
    return;
  }

  _output_image.SaveFile(output_stream, wxBITMAP_TYPE_JPEG);
}

void CppOscilloscopeMainFrame::RefreshTimerOnTimer(wxTimerEvent& event) {
  loadData(_config->getFilepath());
}

void CppOscilloscopeMainFrame::loadData(const std::string& filepath) {
  DataLoader::loadDataFromFile(_config->getFilepath(), _currentData, _previousData, _historicData);
  updateStats();
}

void CppOscilloscopeMainFrame::updateStats() {
  switch (_config->getOperatingMode()) {
    case OperatingMode::CURRENT:
      if (!_currentData.getDataPoints().empty()) {
        yMinValue->SetLabel(std::to_string(_currentData.getYMin()));
        yMaxValue->SetLabel(std::to_string(_currentData.getYMax()));
      }
      break;

    case OperatingMode::CURRENT_AND_PREVIOUS:
      if (!_currentData.getDataPoints().empty() && !_previousData.getDataPoints().empty()) {
        yMinValue->SetLabel(std::to_string(std::min(_currentData.getYMin(), _previousData.getYMin())));
        yMaxValue->SetLabel(std::to_string(std::max(_currentData.getYMax(), _previousData.getYMax())));
      }
      break;

    case OperatingMode::CONTINUOUS:
      if (!_historicData.getDataPoints().empty()) {
        yMinValue->SetLabel(std::to_string(_historicData.getYMin()));
        yMaxValue->SetLabel(std::to_string(_historicData.getYMax()));
      }
      break;
  }
}