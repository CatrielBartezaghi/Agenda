#include "VEditarVenta.h"
#include "Singleton.h"
#include "Principal.h"
#include <wx/msgdlg.h>
#include "Producto.h"
#include "Ventas.h"
#include <windows.h>
VEditarVenta::VEditarVenta(wxWindow *parent, int cual) : MyDialog4(parent) {
	//Se cargan los datos de la venta a editar en la ventana
	indice_venta=cual;
	Principal *Prin=Singleton::ObtenerInstancia(); // obtener el puntero a la unica instancia posible de Agenda
	Venta &v=Prin->RetornarVenta(cual);
	cantidad2=v.vercantidad();
	TextoCantidadVenta->SetValue(wxString()<<v.vercantidad());
	TextoDiaVenta->SetValue(wxString()<<v.verdia());
	TextoMesVenta->SetValue(wxString()<<v.vermes());
	TextoAnioVenta->SetValue(wxString()<<v.veranio());
	TextoNombreVenta->SetValue(v.vernom());
	TextoDNIVenta->SetValue(v.verdni());
	TextoTelefonoVenta->SetValue(v.vertel());
	TextoDNIVenta->SetValue(v.verdni());
	TextoOtroDatoVenta->SetValue(v.verotro());
	
	Boton1->SetLabel("Volver");
	Boton2->SetLabel("Guardar");
	SetTitle("Editar Venta");
	
	//Se cargar los proveedor guardados
	for(size_t i=0;i<Prin->cant_prod();i++) {
		ChoiceVenta->Append(Prin->VerProducto(i).vernombre().c_str());
	}
	
	//Se selecciona el proveedor que estaba asigando
	indice_producto=ChoiceVenta->FindString(Prin->VerVenta(cual).verpro());
	ChoiceVenta->Select(indice_producto);
	if(indice_producto>500 || indice_producto<0){
		indice_producto=0;
		ChoiceVenta->Select(indice_producto);
	}
}

void VEditarVenta::ElegirProductoVenta( wxCommandEvent& event )  {
	//Se guarda el índice del proveedor elegido
	indice_producto=ChoiceVenta->GetSelection();
}

void VEditarVenta::ClickBoton1Venta( wxCommandEvent& event )  {
	EndModal(0);
}

void VEditarVenta::ClickBoton2Venta( wxCommandEvent& event )  {
	//Se convierten y pasan al constructor los nuevos datos escritos/elegidos
	Principal *Prin=Singleton::ObtenerInstancia(); 
	long dia, mes, anio, cantidad;
	TextoDiaVenta->GetValue().ToLong(&dia);
	TextoMesVenta->GetValue().ToLong(&mes);
	TextoAnioVenta->GetValue().ToLong(&anio);
	TextoCantidadVenta->GetValue().ToLong(&cantidad);
	Venta v(Prin->VerProducto(indice_producto),
			dia, mes, anio,
			TextoNombreVenta->GetValue().c_str(),
			TextoTelefonoVenta->GetValue().c_str(),
			TextoDNIVenta->GetValue().c_str(),
			TextoOtroDatoVenta->GetValue().c_str(),
			cantidad);
	resta_stock=(Prin->VerProducto(indice_producto).verstock()+cantidad2)-cantidad;
	
	//Ver si pasa la validación
	string errores = v.ValidarDatosVenta(indice_producto, resta_stock, cantidad);
	if (errores.size()) 
		wxMessageBox(errores);
	else{
		//Se reemplazan y guardan los nuevos datos
		Principal *Prin=Singleton::ObtenerInstancia();
		Prin->ReemplazarVenta(v,indice_venta);
		Prin->GuardarVentas();
		Prin->VerProducto(indice_producto).mod_sto(Prin->VerProducto(indice_producto).verstock()+cantidad2-cantidad);
		Prin->GuardarProductos();
		EndModal(1);
		
		
	}
}

VEditarVenta::~VEditarVenta() {
	
}

void VEditarVenta::ClickAyudaVenta( wxCommandEvent& event )  {
	ShellExecute(NULL,"open","AYUDA_VENTA.png","AYUDA_VENTA.png",NULL,SW_NORMAL); 	
}

