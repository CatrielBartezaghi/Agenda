#ifndef VVENTAGRILLA_H
#define VVENTAGRILLA_H
#include "wxfbWindows.h"

class VVentaGrilla : public MyDialog5 {
	
private:
	
protected:
	void ClickAyudaVentasGrilla( wxCommandEvent& event ) ;
	void ClickEliminarVenta( wxCommandEvent& event ) ;
	void ClickModificarVenta( wxCommandEvent& event ) ;
	void ClickBotonCancelarVenta( wxCommandEvent& event ) ;
	void ElegirBusquedaVenta( wxCommandEvent& event ) ;
	void EnterBuscarVenta( wxCommandEvent& event ) ;
	void ClickBuscarVenta( wxCommandEvent& event ) ;
	void DobleClickGrillaVentas( wxGridEvent& event ) ;
	void ClickGrillaVentas( wxGridEvent& event ) ;
	
public:
	VVentaGrilla(wxWindow *parent=NULL);
	~VVentaGrilla();
	void CargarFilasVen(int i);
};

#endif

