///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d-dirty)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "CppOscilloscope.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,550 ), wxDefaultSize );

	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* PanelSizer;
	PanelSizer = new wxBoxSizer( wxVERTICAL );

	DrawPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	PanelSizer->Add( DrawPanel, 1, wxEXPAND | wxALL, 5 );


	MainSizer->Add( PanelSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* ControlsSizer;
	ControlsSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* LoadFileSizer;
	LoadFileSizer = new wxBoxSizer( wxVERTICAL );

	FileControlText = new wxStaticText( this, wxID_ANY, wxT("File controls"), wxDefaultPosition, wxDefaultSize, 0 );
	FileControlText->Wrap( -1 );
	LoadFileSizer->Add( FileControlText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	LoadFileButton = new wxButton( this, wxID_ANY, wxT("Load file"), wxDefaultPosition, wxDefaultSize, 0 );
	LoadFileSizer->Add( LoadFileButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	ControlsSizer->Add( LoadFileSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* ModeSizer;
	ModeSizer = new wxBoxSizer( wxVERTICAL );

	wxString OperatingModeRadioBoxChoices[] = { wxT("Current data"), wxT("Current and previous data"), wxT("Continuous mode") };
	int OperatingModeRadioBoxNChoices = sizeof( OperatingModeRadioBoxChoices ) / sizeof( wxString );
	OperatingModeRadioBox = new wxRadioBox( this, wxID_ANY, wxT("Operating mode"), wxDefaultPosition, wxDefaultSize, OperatingModeRadioBoxNChoices, OperatingModeRadioBoxChoices, 1, wxRA_SPECIFY_COLS );
	OperatingModeRadioBox->SetSelection( 0 );
	ModeSizer->Add( OperatingModeRadioBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	ControlsSizer->Add( ModeSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* DrawStyleSizer;
	DrawStyleSizer = new wxBoxSizer( wxVERTICAL );

	wxString DrawStyleRadioBoxChoices[] = { wxT("Line"), wxT("Interpolated line"), wxT("Bars") };
	int DrawStyleRadioBoxNChoices = sizeof( DrawStyleRadioBoxChoices ) / sizeof( wxString );
	DrawStyleRadioBox = new wxRadioBox( this, wxID_ANY, wxT("Draw style"), wxDefaultPosition, wxDefaultSize, DrawStyleRadioBoxNChoices, DrawStyleRadioBoxChoices, 1, wxRA_SPECIFY_COLS );
	DrawStyleRadioBox->SetSelection( 0 );
	DrawStyleSizer->Add( DrawStyleRadioBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	ControlsSizer->Add( DrawStyleSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* GridCheckboxSizer;
	GridCheckboxSizer = new wxBoxSizer( wxVERTICAL );

	GridOptionsText = new wxStaticText( this, wxID_ANY, wxT("Grid options"), wxDefaultPosition, wxDefaultSize, 0 );
	GridOptionsText->Wrap( -1 );
	GridCheckboxSizer->Add( GridOptionsText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	ShowGridCheckbox = new wxCheckBox( this, wxID_ANY, wxT("Show grid"), wxDefaultPosition, wxDefaultSize, 0 );
	GridCheckboxSizer->Add( ShowGridCheckbox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	ControlsSizer->Add( GridCheckboxSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* StatsSizer;
	StatsSizer = new wxBoxSizer( wxVERTICAL );

	StatsText = new wxStaticText( this, wxID_ANY, wxT("Stats"), wxDefaultPosition, wxDefaultSize, 0 );
	StatsText->Wrap( -1 );
	StatsSizer->Add( StatsText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* MinSizer;
	MinSizer = new wxBoxSizer( wxHORIZONTAL );

	yMinText = new wxStaticText( this, wxID_ANY, wxT("Y minimum:"), wxDefaultPosition, wxDefaultSize, 0 );
	yMinText->Wrap( -1 );
	MinSizer->Add( yMinText, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	yMinValue = new wxStaticText( this, wxID_ANY, wxT("y_min"), wxDefaultPosition, wxDefaultSize, 0 );
	yMinValue->Wrap( -1 );
	MinSizer->Add( yMinValue, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	StatsSizer->Add( MinSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* MaxSizer;
	MaxSizer = new wxBoxSizer( wxHORIZONTAL );

	yMaxText = new wxStaticText( this, wxID_ANY, wxT("Y maximum:"), wxDefaultPosition, wxDefaultSize, 0 );
	yMaxText->Wrap( -1 );
	MaxSizer->Add( yMaxText, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	yMaxValue = new wxStaticText( this, wxID_ANY, wxT("y_max"), wxDefaultPosition, wxDefaultSize, 0 );
	yMaxValue->Wrap( -1 );
	MaxSizer->Add( yMaxValue, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	StatsSizer->Add( MaxSizer, 0, wxEXPAND, 5 );


	ControlsSizer->Add( StatsSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* BitmapSaveSizer;
	BitmapSaveSizer = new wxBoxSizer( wxVERTICAL );

	BitmapSaveText = new wxStaticText( this, wxID_ANY, wxT("Save to bitmap"), wxDefaultPosition, wxDefaultSize, 0 );
	BitmapSaveText->Wrap( -1 );
	BitmapSaveSizer->Add( BitmapSaveText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	BitmapSaveButton = new wxButton( this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	BitmapSaveSizer->Add( BitmapSaveButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	ControlsSizer->Add( BitmapSaveSizer, 0, wxEXPAND, 5 );


	MainSizer->Add( ControlsSizer, 0, wxEXPAND, 5 );


	this->SetSizer( MainSizer );
	this->Layout();
	RefreshTimer.SetOwner( this, RefreshTimer.GetId() );

	this->Centre( wxBOTH );

	// Connect Events
	DrawPanel->Connect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::DrawPanelOnPaint ), NULL, this );
	DrawPanel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::DrawPanelOnUpdateUI ), NULL, this );
	LoadFileButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::LoadFileButtonOnButtonClick ), NULL, this );
	OperatingModeRadioBox->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainFrame::OperatingModeRadioBoxOnRadioBox ), NULL, this );
	DrawStyleRadioBox->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainFrame::DrawStyleRadioBoxOnRadioBox ), NULL, this );
	ShowGridCheckbox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrame::ShowGridCheckboxOnCheckBox ), NULL, this );
	BitmapSaveButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::BitmapSaveButtonOnButtonClick ), NULL, this );
	this->Connect( RefreshTimer.GetId(), wxEVT_TIMER, wxTimerEventHandler( MainFrame::RefreshTimerOnTimer ) );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	DrawPanel->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::DrawPanelOnPaint ), NULL, this );
	DrawPanel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::DrawPanelOnUpdateUI ), NULL, this );
	LoadFileButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::LoadFileButtonOnButtonClick ), NULL, this );
	OperatingModeRadioBox->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainFrame::OperatingModeRadioBoxOnRadioBox ), NULL, this );
	DrawStyleRadioBox->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainFrame::DrawStyleRadioBoxOnRadioBox ), NULL, this );
	ShowGridCheckbox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrame::ShowGridCheckboxOnCheckBox ), NULL, this );
	BitmapSaveButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::BitmapSaveButtonOnButtonClick ), NULL, this );
	this->Disconnect( RefreshTimer.GetId(), wxEVT_TIMER, wxTimerEventHandler( MainFrame::RefreshTimerOnTimer ) );

}
