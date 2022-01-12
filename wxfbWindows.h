///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXFBWINDOWS_H__
#define __WXFBWINDOWS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/choice.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FBMainWindow
///////////////////////////////////////////////////////////////////////////////
class FBMainWindow : public wxFrame 
{
	private:
		wxButton* BotonAgregar;
	
	protected:
		wxStaticText* BuscarPorNombre;
		wxTextCtrl* EscribirBusqueda;
		wxButton* BotonBuscar;
		wxGrid* grilla;
		wxButton* BotonAyuda;
		wxButton* BotonModificar;
		wxButton* BotonEliminar;
		wxButton* BotonVender;
		wxButton* BotonProveedores;
		wxButton* BotonVentas;
		
		// Virtual event handlers, overide them in your derived class
		virtual void EnterBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void DobleClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAyudaPrincipal( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickModificar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickVender( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickProveedores( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickVentas( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FBMainWindow( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("StockControl"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 715,440 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~FBMainWindow();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog4
///////////////////////////////////////////////////////////////////////////////
class MyDialog4 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText16;
		wxChoice* ChoiceVenta;
		wxStaticText* m_staticText261;
		wxTextCtrl* TextoCantidadVenta;
		wxStaticText* m_staticText24;
		wxStaticText* m_staticText22;
		wxTextCtrl* TextoDiaVenta;
		wxStaticText* m_staticText23;
		wxTextCtrl* TextoMesVenta;
		wxStaticText* m_staticText26;
		wxTextCtrl* TextoAnioVenta;
		wxStaticText* m_staticText20;
		wxStaticText* m_staticText17;
		wxTextCtrl* TextoNombreVenta;
		wxStaticText* m_staticText19;
		wxTextCtrl* TextoTelefonoVenta;
		wxStaticText* m_staticText27;
		wxTextCtrl* TextoDNIVenta;
		wxStaticText* m_staticText28;
		wxTextCtrl* TextoOtroDatoVenta;
		wxButton* BotonAyudaVenta;
		wxButton* Boton1;
		wxButton* Boton2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ElegirProductoVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAyudaVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBoton1Venta( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBoton2Venta( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog4( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 549,336 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog4();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog3
///////////////////////////////////////////////////////////////////////////////
class MyDialog3 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText14;
		wxTextCtrl* EscribirBusquedaProveedor;
		wxButton* BotonBuscarProveedor;
		wxGrid* grilla_prov;
		wxButton* BotonAyudaProveedorGrilla;
		wxButton* CancelarProveedor;
		wxButton* BotonAgregarProveedor;
		wxButton* BotonModificarProveedor;
		wxButton* BotonEliminarProveedor;
		
		// Virtual event handlers, overide them in your derived class
		virtual void EnterBuscarProveedor( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBuscarProveedor( wxCommandEvent& event ) { event.Skip(); }
		virtual void DobleClickGrillaProveedor( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickGrillaProveedor( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAyudaGrillaProveedor( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelarProveedor( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregarProveedor( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickModificarProveedor( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminarProveedor( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog3( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 723,409 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~MyDialog3();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog11
///////////////////////////////////////////////////////////////////////////////
class MyDialog11 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* StaticNombre;
		wxTextCtrl* TextoNombre;
		wxStaticText* StaticTelefono;
		wxTextCtrl* TextoTelefono;
		wxStaticText* StaticDireccion;
		wxTextCtrl* TextoDireccion;
		wxStaticText* StaticEmail;
		wxTextCtrl* TextoEmail;
		wxStaticText* StaticOtro;
		wxTextCtrl* TextoOtroCotacto;
		wxButton* BotonAyudaCargarProv;
		wxButton* boton1;
		wxButton* boton2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickAyudaCargarProv( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBoton1( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBoton2( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog11( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 428,244 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog11();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog1
///////////////////////////////////////////////////////////////////////////////
class MyDialog1 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* StaticNombre;
		wxTextCtrl* TextoNombre;
		wxStaticText* StaticPrecio;
		wxTextCtrl* TextoPrecio;
		wxStaticText* StaticCategoria;
		wxTextCtrl* TextoCategoria;
		wxStaticText* StaticStock;
		wxTextCtrl* TextoStock;
		wxStaticText* StaticProveedor;
		wxChoice* EleccionProveedor;
		wxStaticText* StaticUbicacion;
		wxStaticText* StaticLetra;
		wxTextCtrl* TextoUbiLetra;
		wxStaticText* StaticNumero;
		wxTextCtrl* TextoUbiNumero;
		wxButton* BotonAyudacargarProducto;
		wxButton* boton1;
		wxButton* boton2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ElegirProveedor( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAyudaCargarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBoton1( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBoton2( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog1();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog5
///////////////////////////////////////////////////////////////////////////////
class MyDialog5 : public wxDialog 
{
	private:
	
	protected:
		wxChoice* ChoiceVenta;
		wxTextCtrl* BusquedaVentas;
		wxButton* BotonBusquedaVenta;
		wxGrid* grilla_ven;
		wxButton* BotonAyudaGrillaVentas;
		wxButton* BotonCancelarVenta;
		wxButton* BotonEliminarVenta;
		wxButton* BotonModificar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ElegirBusquedaVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void EnterBuscarVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBuscarVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void DobleClickGrillaVentas( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickGrillaVentas( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAyudaVentasGrilla( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonCancelarVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminarVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickModificarVenta( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog5( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 730,381 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~MyDialog5();
	
};

#endif //__WXFBWINDOWS_H__
