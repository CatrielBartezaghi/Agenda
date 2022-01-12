#ifndef VEDITAR_H
#define VEDITAR_H
#include "wxfbWindows.h"

class VEditar : public MyDialog1 {
	
private:
	int indice_producto=0;
	int a;
	int indice_proveedor;
protected:
	void ClickAyudaCargarProv( wxCommandEvent& event ) ;
	void ClickAyudaCargarProducto( wxCommandEvent& event ) ;
	void ClickBoton1( wxCommandEvent& event ) ;
	void ClickBoton2( wxCommandEvent& event ) ;
	void ElegirProveedor( wxCommandEvent& event ) ;
	
	
public:
	VEditar(wxWindow *parent, int cual);
	~VEditar();
};

#endif

