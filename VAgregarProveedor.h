#ifndef VAGREGARPROVEEDOR_H
#define VAGREGARPROVEEDOR_H
#include "wxfbWindows.h"

class VAgregarProveedor : public MyDialog11 {
	
private:
	
protected:
	void ClickAyudaCargarProv( wxCommandEvent& event ) ;
	void ClickBoton1( wxCommandEvent& event ) ;
	void ClickBoton2( wxCommandEvent& event ) ;
	
public:
	VAgregarProveedor(wxWindow *parent=NULL);
	~VAgregarProveedor();
};

#endif

