///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d-dirty)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef CPPOSCILLOSCOPE_H
#define CPPOSCILLOSCOPE_H


#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/timer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxPanel* DrawPanel;
		wxStaticText* FileControlText;
		wxButton* LoadFileButton;
		wxRadioBox* OperatingModeRadioBox;
		wxRadioBox* DrawStyleRadioBox;
		wxStaticText* GridOptionsText;
		wxCheckBox* ShowGridCheckbox;
		wxStaticText* StatsText;
		wxStaticText* yMinText;
		wxStaticText* m_staticText8;
		wxStaticText* yMaxText;
		wxStaticText* m_staticText9;
		wxStaticText* BitmapSaveText;
		wxButton* BitmapSaveButton;
		wxTimer RefreshTimer;

		// Virtual event handlers, override them in your derived class
		virtual void DrawPanelOnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void DrawPanelOnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void LoadFileButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OperatingModeRadioBoxOnRadioBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void DrawStyleRadioBoxOnRadioBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void ShowGridCheckboxOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void BitmapSaveButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void RefreshTimerOnTimer( wxTimerEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK Project 18"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,550 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

};



#endif /* CPPOSCILLOSCOPE_H */
