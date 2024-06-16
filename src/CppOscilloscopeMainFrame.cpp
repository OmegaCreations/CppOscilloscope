#include "CppOscilloscopeMainFrame.h"
#include <wx/dcbuffer.h>
#include <wx/filedlg.h>

CppOscilloscopeMainFrame::CppOscilloscopeMainFrame(wxWindow* parent)
    : MainFrame(parent), _config{OperatingModeRadioBox->GetSelection(), DrawStyleRadioBox->GetSelection(), ShowGridCheckbox->IsChecked()} {
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
    
  _config.setFilepath(openDataDialog.GetPath().ToStdString());

  RefreshTimer.Start(1000);
}

void CppOscilloscopeMainFrame::OperatingModeRadioBoxOnRadioBox(wxCommandEvent& event) {
  OperatingMode mode = static_cast<OperatingMode>(OperatingModeRadioBox->GetSelection());
  _config.setOperatingMode(mode);
}

void CppOscilloscopeMainFrame::DrawStyleRadioBoxOnRadioBox(wxCommandEvent& event) {
  DrawStyle style = static_cast<DrawStyle>(DrawStyleRadioBox->GetSelection());
  _config.setDrawStyle(style);
}

void CppOscilloscopeMainFrame::ShowGridCheckboxOnCheckBox(wxCommandEvent& event) {
  _config.setShowGrid(ShowGridCheckbox->IsChecked());
}

void CppOscilloscopeMainFrame::BitmapSaveButtonOnButtonClick(wxCommandEvent& event) {
  // TODO: Implement BitmapSaveButtonOnButtonClick
}

void CppOscilloscopeMainFrame::RefreshTimerOnTimer(wxTimerEvent& event) {
  // TODO: Implement RefreshTimerOnTimer
}
