#ifndef VPRINCIPAL_H
#define VPRINCIPAL_H
#include "wxfbWindows.h"
#include "Producto.h"
#include "Proveedor.h"
class VPrincipal : public FBMainWindow {
	
private:
	void CargarFilasProd(int i);

protected:
	void ClickAyudaPrincipal( wxCommandEvent& event ) ;
	void ClickVentas( wxCommandEvent& event ) ;
	void ClickEliminar( wxCommandEvent& event ) ;
	void ClickProveedores( wxCommandEvent& event ) ;
	void ElegirBusqueda( wxCommandEvent& event ) ;
	void EnterBuscar( wxCommandEvent& event ) ;
	void ClickAgregarProveedor( wxCommandEvent& event ) ;
	void ClickBuscar( wxCommandEvent& event ) ;
	void DobleClickGrilla( wxGridEvent& event ) ;
	void ClickGrilla( wxGridEvent& event ) ;
	void ClickAgregar( wxCommandEvent& event ) ;
	void ClickModificar( wxCommandEvent& event ) ;
	void ClickVender( wxCommandEvent& event ) ;
	
public:
	VPrincipal(wxWindow *parent=NULL);
	~VPrincipal();
	
};

#endif

