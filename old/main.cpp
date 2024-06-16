#include <wx/wx.h>
#include <memory>
#include "GUIMyFrame1.h"
#include "Buffer.h"


// Inicjalizacja aplikacji WxWidgets
// =================================


class MyApp : public wxApp {

public:

 virtual bool OnInit();
 virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

// inicjalizacja zmiennej
Buffer::ChartMap Buffer::_chartData;
// TESTOWE ZA£ADOWANIE PLIKU
bool res = Buffer::readDataFromFile("Test.txt", "1");

bool MyApp::OnInit() 
{


 SetProcessDPIAware();
 wxFrame *mainFrame = new GUIMyFrame1(NULL);
 mainFrame->Show(true);
 SetTopWindow(mainFrame);

 return true;
}