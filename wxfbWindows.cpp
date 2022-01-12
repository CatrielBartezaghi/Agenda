///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfbWindows.h"

///////////////////////////////////////////////////////////////////////////

FBMainWindow::FBMainWindow( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	BuscarPorNombre = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	BuscarPorNombre->Wrap( -1 );
	bSizer3->Add( BuscarPorNombre, 0, wxALL, 5 );
	
	EscribirBusqueda = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer3->Add( EscribirBusqueda, 1, wxALL, 5 );
	
	BotonBuscar = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( BotonBuscar, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );
	
	grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla->CreateGrid( 0, 7 );
	grilla->EnableEditing( false );
	grilla->EnableGridLines( true );
	grilla->EnableDragGridSize( false );
	grilla->SetMargins( 0, 0 );
	
	// Columns
	grilla->SetColSize( 0, 180 );
	grilla->SetColSize( 1, 54 );
	grilla->SetColSize( 2, 160 );
	grilla->SetColSize( 3, 64 );
	grilla->SetColSize( 4, 70 );
	grilla->SetColSize( 5, 70 );
	grilla->SetColSize( 6, 102 );
	grilla->EnableDragColMove( false );
	grilla->EnableDragColSize( true );
	grilla->SetColLabelSize( 30 );
	grilla->SetColLabelValue( 0, wxT("Nombre") );
	grilla->SetColLabelValue( 1, wxT("Precio") );
	grilla->SetColLabelValue( 2, wxT("Categoría") );
	grilla->SetColLabelValue( 3, wxT("Stock") );
	grilla->SetColLabelValue( 4, wxT("Letra") );
	grilla->SetColLabelValue( 5, wxT("Número") );
	grilla->SetColLabelValue( 6, wxT("Proveedor") );
	grilla->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla->EnableDragRowSize( true );
	grilla->SetRowLabelSize( 2 );
	grilla->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2->Add( grilla, 1, wxALL|wxEXPAND, 0 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	BotonAyuda = new wxButton( this, wxID_ANY, wxT("Ayuda"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( BotonAyuda, 0, wxALL, 5 );
	
	BotonAgregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( BotonAgregar, 0, wxALL, 5 );
	
	BotonModificar = new wxButton( this, wxID_ANY, wxT("Modificar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( BotonModificar, 0, wxALL, 5 );
	
	BotonEliminar = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( BotonEliminar, 0, wxALL, 5 );
	
	BotonVender = new wxButton( this, wxID_ANY, wxT("Vender"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( BotonVender, 0, wxALL, 5 );
	
	BotonProveedores = new wxButton( this, wxID_ANY, wxT("Proveedores"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( BotonProveedores, 0, wxALL, 5 );
	
	BotonVentas = new wxButton( this, wxID_ANY, wxT("Ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( BotonVentas, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer4, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	// Connect Events
	EscribirBusqueda->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FBMainWindow::EnterBuscar ), NULL, this );
	BotonBuscar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickBuscar ), NULL, this );
	grilla->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( FBMainWindow::DobleClickGrilla ), NULL, this );
	grilla->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( FBMainWindow::ClickGrilla ), NULL, this );
	BotonAyuda->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickAyudaPrincipal ), NULL, this );
	BotonAgregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickAgregar ), NULL, this );
	BotonModificar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickModificar ), NULL, this );
	BotonEliminar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickEliminar ), NULL, this );
	BotonVender->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickVender ), NULL, this );
	BotonProveedores->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickProveedores ), NULL, this );
	BotonVentas->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickVentas ), NULL, this );
}

FBMainWindow::~FBMainWindow()
{
	// Disconnect Events
	EscribirBusqueda->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( FBMainWindow::EnterBuscar ), NULL, this );
	BotonBuscar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickBuscar ), NULL, this );
	grilla->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( FBMainWindow::DobleClickGrilla ), NULL, this );
	grilla->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( FBMainWindow::ClickGrilla ), NULL, this );
	BotonAyuda->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickAyudaPrincipal ), NULL, this );
	BotonAgregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickAgregar ), NULL, this );
	BotonModificar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickModificar ), NULL, this );
	BotonEliminar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickEliminar ), NULL, this );
	BotonVender->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickVender ), NULL, this );
	BotonProveedores->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickProveedores ), NULL, this );
	BotonVentas->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FBMainWindow::ClickVentas ), NULL, this );
	
}

MyDialog4::MyDialog4( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Producto:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer25->Add( m_staticText16, 0, wxALL, 5 );
	
	wxArrayString ChoiceVentaChoices;
	ChoiceVenta = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, ChoiceVentaChoices, 0 );
	ChoiceVenta->SetSelection( 0 );
	bSizer25->Add( ChoiceVenta, 1, wxALL, 5 );
	
	m_staticText261 = new wxStaticText( this, wxID_ANY, wxT("Cantidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText261->Wrap( -1 );
	bSizer25->Add( m_staticText261, 0, wxALL, 5 );
	
	TextoCantidadVenta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( TextoCantidadVenta, 0, wxALL, 5 );
	
	
	bSizer24->Add( bSizer25, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Fecha de Venta:  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer30->Add( m_staticText24, 0, wxALL, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("dd:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer30->Add( m_staticText22, 0, wxALL, 5 );
	
	TextoDiaVenta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( TextoDiaVenta, 0, wxALL, 5 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("mm:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer30->Add( m_staticText23, 0, wxALL, 5 );
	
	TextoMesVenta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( TextoMesVenta, 0, wxALL, 5 );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("aaaa:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	bSizer30->Add( m_staticText26, 0, wxALL, 5 );
	
	TextoAnioVenta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( TextoAnioVenta, 0, wxALL, 5 );
	
	
	bSizer24->Add( bSizer30, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("DATOS CLIENTE:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer29->Add( m_staticText20, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer24->Add( bSizer29, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer26->Add( m_staticText17, 0, wxALL, 5 );
	
	TextoNombreVenta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( TextoNombreVenta, 1, wxALL, 5 );
	
	
	bSizer24->Add( bSizer26, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Teléfono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer27->Add( m_staticText19, 0, wxALL, 5 );
	
	TextoTelefonoVenta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( TextoTelefonoVenta, 1, wxALL, 5 );
	
	
	bSizer24->Add( bSizer27, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	bSizer32->Add( m_staticText27, 0, wxALL, 5 );
	
	TextoDNIVenta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer32->Add( TextoDNIVenta, 1, wxALL, 5 );
	
	
	bSizer24->Add( bSizer32, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Otro Dato:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer33->Add( m_staticText28, 0, wxALL, 5 );
	
	TextoOtroDatoVenta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( TextoOtroDatoVenta, 1, wxALL, 5 );
	
	
	bSizer24->Add( bSizer33, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	BotonAyudaVenta = new wxButton( this, wxID_ANY, wxT("Ayuda"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( BotonAyudaVenta, 0, wxALL, 5 );
	
	Boton1 = new wxButton( this, wxID_ANY, wxT("Boton1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( Boton1, 0, wxALL, 5 );
	
	Boton2 = new wxButton( this, wxID_ANY, wxT("Boton2"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( Boton2, 0, wxALL, 5 );
	
	
	bSizer24->Add( bSizer34, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer24 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	ChoiceVenta->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog4::ElegirProductoVenta ), NULL, this );
	BotonAyudaVenta->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::ClickAyudaVenta ), NULL, this );
	Boton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::ClickBoton1Venta ), NULL, this );
	Boton2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::ClickBoton2Venta ), NULL, this );
}

MyDialog4::~MyDialog4()
{
	// Disconnect Events
	ChoiceVenta->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog4::ElegirProductoVenta ), NULL, this );
	BotonAyudaVenta->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::ClickAyudaVenta ), NULL, this );
	Boton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::ClickBoton1Venta ), NULL, this );
	Boton2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::ClickBoton2Venta ), NULL, this );
	
}

MyDialog3::MyDialog3( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer31->Add( m_staticText14, 0, wxALL, 5 );
	
	EscribirBusquedaProveedor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer31->Add( EscribirBusquedaProveedor, 1, wxALL, 5 );
	
	BotonBuscarProveedor = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( BotonBuscarProveedor, 0, wxALL, 5 );
	
	
	bSizer3->Add( bSizer31, 0, wxEXPAND, 5 );
	
	grilla_prov = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_prov->CreateGrid( 0, 5 );
	grilla_prov->EnableEditing( false );
	grilla_prov->EnableGridLines( true );
	grilla_prov->EnableDragGridSize( false );
	grilla_prov->SetMargins( 0, 0 );
	
	// Columns
	grilla_prov->SetColSize( 0, 179 );
	grilla_prov->SetColSize( 1, 95 );
	grilla_prov->SetColSize( 2, 164 );
	grilla_prov->SetColSize( 3, 134 );
	grilla_prov->SetColSize( 4, 127 );
	grilla_prov->EnableDragColMove( false );
	grilla_prov->EnableDragColSize( true );
	grilla_prov->SetColLabelSize( 30 );
	grilla_prov->SetColLabelValue( 0, wxT("Nombre") );
	grilla_prov->SetColLabelValue( 1, wxT("Teléfono") );
	grilla_prov->SetColLabelValue( 2, wxT("Dirección") );
	grilla_prov->SetColLabelValue( 3, wxT("E-mail") );
	grilla_prov->SetColLabelValue( 4, wxT("Otro Contacto") );
	grilla_prov->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_prov->EnableDragRowSize( true );
	grilla_prov->SetRowLabelSize( 2 );
	grilla_prov->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_prov->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer3->Add( grilla_prov, 1, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	BotonAyudaProveedorGrilla = new wxButton( this, wxID_ANY, wxT("Ayuda"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( BotonAyudaProveedorGrilla, 0, wxALL, 5 );
	
	CancelarProveedor = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( CancelarProveedor, 0, wxALL, 5 );
	
	BotonAgregarProveedor = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( BotonAgregarProveedor, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	BotonModificarProveedor = new wxButton( this, wxID_ANY, wxT("Modificar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( BotonModificarProveedor, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	BotonEliminarProveedor = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( BotonEliminarProveedor, 0, wxALL, 5 );
	
	
	bSizer3->Add( bSizer4, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	EscribirBusquedaProveedor->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog3::EnterBuscarProveedor ), NULL, this );
	BotonBuscarProveedor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickBuscarProveedor ), NULL, this );
	grilla_prov->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( MyDialog3::DobleClickGrillaProveedor ), NULL, this );
	grilla_prov->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( MyDialog3::ClickGrillaProveedor ), NULL, this );
	BotonAyudaProveedorGrilla->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickAyudaGrillaProveedor ), NULL, this );
	CancelarProveedor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickCancelarProveedor ), NULL, this );
	BotonAgregarProveedor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickAgregarProveedor ), NULL, this );
	BotonModificarProveedor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickModificarProveedor ), NULL, this );
	BotonEliminarProveedor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickEliminarProveedor ), NULL, this );
}

MyDialog3::~MyDialog3()
{
	// Disconnect Events
	EscribirBusquedaProveedor->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog3::EnterBuscarProveedor ), NULL, this );
	BotonBuscarProveedor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickBuscarProveedor ), NULL, this );
	grilla_prov->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( MyDialog3::DobleClickGrillaProveedor ), NULL, this );
	grilla_prov->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( MyDialog3::ClickGrillaProveedor ), NULL, this );
	BotonAyudaProveedorGrilla->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickAyudaGrillaProveedor ), NULL, this );
	CancelarProveedor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickCancelarProveedor ), NULL, this );
	BotonAgregarProveedor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickAgregarProveedor ), NULL, this );
	BotonModificarProveedor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickModificarProveedor ), NULL, this );
	BotonEliminarProveedor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::ClickEliminarProveedor ), NULL, this );
	
}

MyDialog11::MyDialog11( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticNombre = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticNombre->Wrap( -1 );
	bSizer5->Add( StaticNombre, 0, wxALL, 5 );
	
	TextoNombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( TextoNombre, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticTelefono = new wxStaticText( this, wxID_ANY, wxT("Teléfono:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticTelefono->Wrap( -1 );
	bSizer51->Add( StaticTelefono, 0, wxALL, 5 );
	
	TextoTelefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( TextoTelefono, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer51, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticDireccion = new wxStaticText( this, wxID_ANY, wxT("Dirección:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticDireccion->Wrap( -1 );
	bSizer52->Add( StaticDireccion, 0, wxALL, 5 );
	
	TextoDireccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( TextoDireccion, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer52, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticEmail = new wxStaticText( this, wxID_ANY, wxT("E-mail:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticEmail->Wrap( -1 );
	bSizer53->Add( StaticEmail, 0, wxALL, 5 );
	
	TextoEmail = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( TextoEmail, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer53, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticOtro = new wxStaticText( this, wxID_ANY, wxT("Otro Contacto:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticOtro->Wrap( -1 );
	bSizer12->Add( StaticOtro, 0, wxALL, 5 );
	
	TextoOtroCotacto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( TextoOtroCotacto, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer12, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	BotonAyudaCargarProv = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( BotonAyudaCargarProv, 0, wxALL, 5 );
	
	boton1 = new wxButton( this, wxID_ANY, wxT("Boton 1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( boton1, 0, wxALL, 5 );
	
	boton2 = new wxButton( this, wxID_ANY, wxT("Boton 2"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( boton2, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer13, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	// Connect Events
	BotonAyudaCargarProv->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog11::ClickAyudaCargarProv ), NULL, this );
	boton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog11::ClickBoton1 ), NULL, this );
	boton2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog11::ClickBoton2 ), NULL, this );
}

MyDialog11::~MyDialog11()
{
	// Disconnect Events
	BotonAyudaCargarProv->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog11::ClickAyudaCargarProv ), NULL, this );
	boton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog11::ClickBoton1 ), NULL, this );
	boton2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog11::ClickBoton2 ), NULL, this );
	
}

MyDialog1::MyDialog1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticNombre = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticNombre->Wrap( -1 );
	bSizer5->Add( StaticNombre, 0, wxALL, 5 );
	
	TextoNombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( TextoNombre, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticPrecio = new wxStaticText( this, wxID_ANY, wxT("Precio:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticPrecio->Wrap( -1 );
	bSizer51->Add( StaticPrecio, 0, wxALL, 5 );
	
	TextoPrecio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( TextoPrecio, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer51, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticCategoria = new wxStaticText( this, wxID_ANY, wxT("Categoría:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticCategoria->Wrap( -1 );
	bSizer52->Add( StaticCategoria, 0, wxALL, 5 );
	
	TextoCategoria = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( TextoCategoria, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer52, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticStock = new wxStaticText( this, wxID_ANY, wxT("Stock:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticStock->Wrap( -1 );
	bSizer53->Add( StaticStock, 0, wxALL, 5 );
	
	TextoStock = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( TextoStock, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer53, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticProveedor = new wxStaticText( this, wxID_ANY, wxT("Proveedor:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticProveedor->Wrap( -1 );
	bSizer12->Add( StaticProveedor, 0, wxALL, 5 );
	
	wxArrayString EleccionProveedorChoices;
	EleccionProveedor = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, EleccionProveedorChoices, 0 );
	EleccionProveedor->SetSelection( 0 );
	bSizer12->Add( EleccionProveedor, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer12, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticUbicacion = new wxStaticText( this, wxID_ANY, wxT("Ubicación:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticUbicacion->Wrap( -1 );
	bSizer19->Add( StaticUbicacion, 0, wxALL, 5 );
	
	StaticLetra = new wxStaticText( this, wxID_ANY, wxT("Letra:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticLetra->Wrap( -1 );
	bSizer19->Add( StaticLetra, 0, wxALL, 5 );
	
	TextoUbiLetra = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( TextoUbiLetra, 0, wxALL, 5 );
	
	
	bSizer54->Add( bSizer19, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	StaticNumero = new wxStaticText( this, wxID_ANY, wxT("Número:"), wxDefaultPosition, wxDefaultSize, 0 );
	StaticNumero->Wrap( -1 );
	bSizer20->Add( StaticNumero, 0, wxALL, 5 );
	
	TextoUbiNumero = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( TextoUbiNumero, 0, wxALL, 5 );
	
	
	bSizer54->Add( bSizer20, 1, wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer54, 1, wxEXPAND, 5 );
	
	wxBoxSizer* BotonAyuda;
	BotonAyuda = new wxBoxSizer( wxHORIZONTAL );
	
	BotonAyudacargarProducto = new wxButton( this, wxID_ANY, wxT("Ayuda"), wxDefaultPosition, wxDefaultSize, 0 );
	BotonAyuda->Add( BotonAyudacargarProducto, 0, wxALL, 5 );
	
	boton1 = new wxButton( this, wxID_ANY, wxT("Boton 1"), wxDefaultPosition, wxDefaultSize, 0 );
	BotonAyuda->Add( boton1, 0, wxALL, 5 );
	
	boton2 = new wxButton( this, wxID_ANY, wxT("Boton 2"), wxDefaultPosition, wxDefaultSize, 0 );
	BotonAyuda->Add( boton2, 0, wxALL, 5 );
	
	
	bSizer4->Add( BotonAyuda, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );
	
	// Connect Events
	EleccionProveedor->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::ElegirProveedor ), NULL, this );
	BotonAyudacargarProducto->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::ClickAyudaCargarProducto ), NULL, this );
	boton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::ClickBoton1 ), NULL, this );
	boton2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::ClickBoton2 ), NULL, this );
}

MyDialog1::~MyDialog1()
{
	// Disconnect Events
	EleccionProveedor->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog1::ElegirProveedor ), NULL, this );
	BotonAyudacargarProducto->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::ClickAyudaCargarProducto ), NULL, this );
	boton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::ClickBoton1 ), NULL, this );
	boton2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::ClickBoton2 ), NULL, this );
	
}

MyDialog5::MyDialog5( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString ChoiceVentaChoices[] = { wxT("Cliente"), wxT("Producto") };
	int ChoiceVentaNChoices = sizeof( ChoiceVentaChoices ) / sizeof( wxString );
	ChoiceVenta = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, ChoiceVentaNChoices, ChoiceVentaChoices, 0 );
	ChoiceVenta->SetSelection( 0 );
	bSizer35->Add( ChoiceVenta, 0, wxALL, 5 );
	
	BusquedaVentas = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer35->Add( BusquedaVentas, 1, wxALL, 5 );
	
	BotonBusquedaVenta = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( BotonBusquedaVenta, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	
	bSizer33->Add( bSizer35, 0, wxEXPAND, 5 );
	
	grilla_ven = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_ven->CreateGrid( 0, 7 );
	grilla_ven->EnableEditing( false );
	grilla_ven->EnableGridLines( true );
	grilla_ven->EnableDragGridSize( false );
	grilla_ven->SetMargins( 0, 0 );
	
	// Columns
	grilla_ven->SetColSize( 0, 180 );
	grilla_ven->SetColSize( 1, 62 );
	grilla_ven->SetColSize( 2, 135 );
	grilla_ven->SetColSize( 3, 70 );
	grilla_ven->SetColSize( 4, 107 );
	grilla_ven->SetColSize( 5, 70 );
	grilla_ven->SetColSize( 6, 77 );
	grilla_ven->EnableDragColMove( false );
	grilla_ven->EnableDragColSize( true );
	grilla_ven->SetColLabelSize( 30 );
	grilla_ven->SetColLabelValue( 0, wxT("Cliente") );
	grilla_ven->SetColLabelValue( 1, wxT("DNI") );
	grilla_ven->SetColLabelValue( 2, wxT("Teléfono") );
	grilla_ven->SetColLabelValue( 3, wxT("Otro Dato:") );
	grilla_ven->SetColLabelValue( 4, wxT("Producto") );
	grilla_ven->SetColLabelValue( 5, wxT("Precio total") );
	grilla_ven->SetColLabelValue( 6, wxT("Fecha") );
	grilla_ven->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_ven->EnableDragRowSize( true );
	grilla_ven->SetRowLabelSize( 2 );
	grilla_ven->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_ven->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer33->Add( grilla_ven, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	BotonAyudaGrillaVentas = new wxButton( this, wxID_ANY, wxT("Ayuda"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( BotonAyudaGrillaVentas, 0, wxALL, 5 );
	
	BotonCancelarVenta = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( BotonCancelarVenta, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	BotonEliminarVenta = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( BotonEliminarVenta, 0, wxALL, 5 );
	
	BotonModificar = new wxButton( this, wxID_ANY, wxT("Modificar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( BotonModificar, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	
	bSizer33->Add( bSizer34, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer33 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	ChoiceVenta->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog5::ElegirBusquedaVenta ), NULL, this );
	BusquedaVentas->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog5::EnterBuscarVenta ), NULL, this );
	BotonBusquedaVenta->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog5::ClickBuscarVenta ), NULL, this );
	grilla_ven->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( MyDialog5::DobleClickGrillaVentas ), NULL, this );
	grilla_ven->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( MyDialog5::ClickGrillaVentas ), NULL, this );
	BotonAyudaGrillaVentas->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog5::ClickAyudaVentasGrilla ), NULL, this );
	BotonCancelarVenta->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog5::ClickBotonCancelarVenta ), NULL, this );
	BotonEliminarVenta->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog5::ClickEliminarVenta ), NULL, this );
	BotonModificar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog5::ClickModificarVenta ), NULL, this );
}

MyDialog5::~MyDialog5()
{
	// Disconnect Events
	ChoiceVenta->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog5::ElegirBusquedaVenta ), NULL, this );
	BusquedaVentas->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog5::EnterBuscarVenta ), NULL, this );
	BotonBusquedaVenta->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog5::ClickBuscarVenta ), NULL, this );
	grilla_ven->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( MyDialog5::DobleClickGrillaVentas ), NULL, this );
	grilla_ven->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( MyDialog5::ClickGrillaVentas ), NULL, this );
	BotonAyudaGrillaVentas->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog5::ClickAyudaVentasGrilla ), NULL, this );
	BotonCancelarVenta->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog5::ClickBotonCancelarVenta ), NULL, this );
	BotonEliminarVenta->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog5::ClickEliminarVenta ), NULL, this );
	BotonModificar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog5::ClickModificarVenta ), NULL, this );
	
}
