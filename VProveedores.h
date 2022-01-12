#ifndef VPROVEEDORES_H
#define VPROVEEDORES_H
#include "wxfbWindows.h"

class VProveedores : public MyDialog3 {
	
private:
	void CargarFilasProv(int j);
protected:
	void ClickAyudaGrillaProveedor( wxCommandEvent& event ) ;
	void ClickEliminarProveedor( wxCommandEvent& event ) ;
	void EnterBuscarProveedor( wxCommandEvent& event ) ;
	void ClickBuscarProveedor( wxCommandEvent& event ) ;
	void DobleClickGrillaProveedor( wxGridEvent& event ) ;
	void ClickGrillaProveedor( wxGridEvent& event ) ;
	void ClickModificarProveedor( wxCommandEvent& event ) ;
	void ClickCancelarProveedor( wxCommandEvent& event ) ;
	void ElegirBusqueda( wxCommandEvent& event ) ;
	void EnterBuscar( wxCommandEvent& event ) ;
	void ClickBuscar( wxCommandEvent& event ) ;
	void DobleClickGrilla( wxGridEvent& event ) ;
	void ClickGrilla( wxGridEvent& event ) ;
	void ClickAgregar( wxCommandEvent& event ) ;
	void ClickModificar( wxCommandEvent& event ) ;
	void ClickAgregarProveedor( wxCommandEvent& event ) ;
	
public:
	VProveedores(wxWindow *parent=NULL);
	~VProveedores();
};

#endif

