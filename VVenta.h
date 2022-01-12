#ifndef VVENTA_H
#define VVENTA_H
#include "wxfbWindows.h"

class VVenta : public MyDialog4 {
	
private:
	int a;
	int resta_stock;
protected:
	void ClickAyudaVenta( wxCommandEvent& event ) ;
	void ElegirProductoVenta( wxCommandEvent& event ) ;
	void ClickBoton1Venta( wxCommandEvent& event ) ;
	void ClickBoton2Venta( wxCommandEvent& event ) ;
	
public:
	VVenta(wxWindow *parent, int pos);
	~VVenta();
};

#endif

