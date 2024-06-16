#include <wx/wx.h>
#include "CppOscilloscopeMainFrame.h"

class MyApp : public wxApp {
 public:
  bool OnInit() override;
  int OnExit() override;
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  CppOscilloscopeMainFrame* mainFrame = new CppOscilloscopeMainFrame(NULL);

  mainFrame->Show(true);
  SetTopWindow(mainFrame);

  return true;
}

int MyApp::OnExit() {
  return 0;
}
