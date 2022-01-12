#ifndef VEDITARVENTA_H
#define VEDITARVENTA_H
#include "wxfbWindows.h"

class VEditarVenta : public MyDialog4 {
	
private:
	int a;
	int resta_stock;
	int indice_venta;
	int indice_producto;
	int cantidad2;
protected:
	void ClickAyudaVenta( wxCommandEvent& event ) ;
	void ElegirProductoVenta( wxCommandEvent& event ) ;
	void ClickBoton1Venta( wxCommandEvent& event ) ;
	void ClickBoton2Venta( wxCommandEvent& event ) ;
	
public:
	VEditarVenta(wxWindow *parent, int cual);
	~VEditarVenta();
};

#endif

