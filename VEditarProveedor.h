#ifndef VEDITARPROVEEDOR_H
#define VEDITARPROVEEDOR_H
#include "wxfbWindows.h"

class VEditarProveedor : public MyDialog11 {
	
private:
	int indice_proveedor;
protected:
	void ClickAyudaCargarProv( wxCommandEvent& event ) ;
	void ClickBoton1( wxCommandEvent& event ) ;
	void ClickBoton2( wxCommandEvent& event ) ;
	
public:
	VEditarProveedor(wxWindow *parent, int cual);
	~VEditarProveedor();
};

#endif

