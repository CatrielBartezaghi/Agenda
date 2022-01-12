#include "VVenta.h"
#include "Principal.h"
#include "Singleton.h"
#include <wx/msgdlg.h>
#include <ctime>
#include <wx/choice.h>
#include <windows.h>
VVenta::VVenta(wxWindow *parent, int cual) : MyDialog4(parent) {
	
	//Se asignan rótulos de la ventana
	SetTitle("Venta"); 
	Boton1->SetLabel("Cancelar"); 
	Boton2->SetLabel("Vender"); 
	a=cual;
	Principal *Prin=Singleton::ObtenerInstancia();
	
	//Cargar productos a elegir
	for(size_t i=0;i<Prin->cant_prod();i++) {
		ChoiceVenta->Append(Prin->VerProducto(i).vernombre().c_str());
	}
	ChoiceVenta->Select(a); //Se posiciona en la venta que se habia seleccionado en la grilla productos
	
	//Se obtiene la fecha del sistema y se carga automaticamente en los cuadros de textos 
	struct tm *tiempo;
	time_t fecha_sistema;
	time(&fecha_sistema);
	tiempo=localtime(&fecha_sistema);
	TextoDiaVenta->AppendText(wxString()<<tiempo->tm_mday);
	TextoMesVenta->AppendText(wxString()<<tiempo->tm_mon + 1);
	TextoAnioVenta->AppendText(wxString()<<tiempo->tm_year + 1900);
}


void VVenta::ElegirProductoVenta( wxCommandEvent& event )  {
	a=ChoiceVenta->GetSelection(); //Se guarda el producto elegido
}

void VVenta::ClickBoton1Venta( wxCommandEvent& event )  {
	EndModal(0);
}

void VVenta::ClickBoton2Venta( wxCommandEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	if(Prin->cant_prod()==0){
		wxMessageBox("Aun no has cargado ningun producto!");
	}else{
	long dia, mes, anio, cantidad; //Convertir cadenas a numeros
	TextoDiaVenta->GetValue().ToLong(&dia);
	TextoMesVenta->GetValue().ToLong(&mes);
	TextoAnioVenta->GetValue().ToLong(&anio);
	TextoCantidadVenta->GetValue().ToLong(&cantidad);
	
	//Se convierten y pasan los datos escritos/elegidos
	Venta v(Prin->VerProducto(a),
				dia, mes, anio,
			   TextoNombreVenta->GetValue().c_str(),
			   TextoTelefonoVenta->GetValue().c_str(),
			   TextoDNIVenta->GetValue().c_str(),
			   TextoOtroDatoVenta->GetValue().c_str(),
				cantidad);
	
	//Se resta la cantidad de producto elegido en el stock del mismo
	resta_stock=Prin->VerProducto(a).verstock()-cantidad;
	
	//Ver si pasa la validación
	string errores = v.ValidarDatosVenta(a, resta_stock, cantidad);
	if (errores.size()) // ver si no pasa la validacion
		wxMessageBox(errores);
	else{
		//Se guarda la venta y el producto con el nuevo stock
		Principal *Prin=Singleton::ObtenerInstancia();
		Prin->AgregarVenta(v);
		Prin->GuardarVentas();
		Prin->VerProducto(a).mod_sto(Prin->VerProducto(a).verstock()-cantidad);
		Prin->GuardarProductos();
		
		EndModal(1);
		
		
	}
}
}
VVenta::~VVenta() {
	
}

void VVenta::ClickAyudaVenta( wxCommandEvent& event )  {
	ShellExecute(NULL,"open","AYUDA_VENTA.png","AYUDA_VENTA.png",NULL,SW_NORMAL); 	
}

