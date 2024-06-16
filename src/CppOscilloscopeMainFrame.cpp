#include "CppOscilloscopeMainFrame.h"
#include <wx/dcbuffer.h>
#include <wx/filedlg.h>
#include "DataLoader.h"

CppOscilloscopeMainFrame::CppOscilloscopeMainFrame(wxWindow* parent)
    : MainFrame(parent),
      _config{std::make_shared<Config>(OperatingModeRadioBox->GetSelection(), DrawStyleRadioBox->GetSelection(), ShowGridCheckbox->IsChecked())} {
  DrawPanel->SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void CppOscilloscopeMainFrame::DrawPanelOnPaint(wxPaintEvent& event) {
  wxAutoBufferedPaintDC dc(DrawPanel);
}

void CppOscilloscopeMainFrame::DrawPanelOnUpdateUI(wxUpdateUIEvent& event) {
  DrawPanel->Refresh();
}

void CppOscilloscopeMainFrame::LoadFileButtonOnButtonClick(wxCommandEvent& event) {
  wxFileDialog openDataDialog(this, "Open the data file", "", "dane.dat", "DAT files (*.dat)|*.dat", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

  if (openDataDialog.ShowModal() == wxID_CANCEL) {
    return;
  }

  _config->setFilepath(openDataDialog.GetPath().ToStdString());
  loadData(_config->getFilepath());

  RefreshTimer.Start(1000);
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
  // TODO: Implement BitmapSaveButtonOnButtonClick
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
      yMinValue->SetLabel(std::to_string(_currentData.getYMin()));
      yMaxValue->SetLabel(std::to_string(_currentData.getYMax()));
      break;

    case OperatingMode::CURRENT_AND_PREVIOUS:
      yMinValue->SetLabel(std::to_string(std::min(_currentData.getYMin(), _previousData.getYMin())));
      yMaxValue->SetLabel(std::to_string(std::max(_currentData.getYMax(), _previousData.getYMax())));
      break;

    case OperatingMode::CONTINUOUS:
      yMinValue->SetLabel(std::to_string(_historicData.getYMin()));
      yMaxValue->SetLabel(std::to_string(_historicData.getYMax()));
      break;
  }
}