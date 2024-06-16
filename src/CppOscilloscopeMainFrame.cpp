#include "CppOscilloscopeMainFrame.h"

CppOscilloscopeMainFrame::CppOscilloscopeMainFrame(wxWindow* parent)
    : MainFrame(parent), _config{OperatingModeRadioBox->GetSelection(), DrawStyleRadioBox->GetSelection(), ShowGridCheckbox->IsChecked()} {};

void CppOscilloscopeMainFrame::DrawPanelOnPaint(wxPaintEvent& event) {
  // TODO: Implement DrawPanelOnPaint
}

void CppOscilloscopeMainFrame::DrawPanelOnUpdateUI(wxUpdateUIEvent& event) {
  // TODO: Implement DrawPanelOnUpdateUI
}

void CppOscilloscopeMainFrame::LoadFileButtonOnButtonClick(wxCommandEvent& event) {
  // TODO: Implement LoadFileButtonOnButtonClick
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
