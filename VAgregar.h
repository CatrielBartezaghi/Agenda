#ifndef VAGREGAR_H
#define VAGREGAR_H
#include "wxfbWindows.h"

class VAgregar : public MyDialog1 {
	
private:
	int a=0;
	
protected:
	void ClickAyudaCargarProv( wxCommandEvent& event ) ;
	void ClickAyudaCargarProducto( wxCommandEvent& event ) ;
	void ClickBoton1( wxCommandEvent& event ) ;
	void ClickBoton2( wxCommandEvent& event ) ;
	void ElegirProveedor( wxCommandEvent& event ) ;
	
public:
	VAgregar(wxWindow *parent=NULL);
	~VAgregar();
};

#endif

