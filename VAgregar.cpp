#include "VAgregar.h"
#include "Producto.h"
#include <wx/msgdlg.h>
#include "Singleton.h"
#include "Principal.h"
#include "Proveedor.h"
#include <windows.h>
#include <wx/string.h>
#include <wx/choice.h>
VAgregar::VAgregar(wxWindow *parent) : MyDialog1(parent) {
	//Ventana agregar Producto
	SetTitle("Agregar Producto");
	boton1->SetLabel("Cancelar"); 
	boton2->SetLabel("Agregar"); 
	Principal *Prin=Singleton::ObtenerInstancia();
	//Se cargar los proveedores guardados en el choice
	for(size_t i=0;i<Prin->cant_prov();i++) {
	EleccionProveedor->Append(Prin->VerProveedor(i).vernom().c_str());
	}
	EleccionProveedor->Select(a);
}



void VAgregar::ElegirProveedor( wxCommandEvent& event )  {
	a=EleccionProveedor->GetSelection(); //Se guarda la posición elegida por el usuario
	
}

void VAgregar::ClickBoton1( wxCommandEvent& event )  {
	EndModal(0);
	
}

void VAgregar::ClickBoton2( wxCommandEvent& event )  {

	Principal *Prin=Singleton::ObtenerInstancia();
	if(Prin->cant_prov()==0){
		wxMessageBox("Aun no has cargado ningun proveedor!");
	}else{
	//convertir cadenas a numeros
	double precio; 
	long stock, numero; 
	TextoPrecio->GetValue().ToDouble(&precio);
	TextoStock->GetValue().ToLong(&stock);
	TextoUbiNumero->GetValue().ToLong(&numero);
	
	//Se convierten y pasan los datos escritos/elegidos
	Producto p(TextoNombre->GetValue().c_str(),
			   precio,
			   TextoCategoria->GetValue().c_str(),
			   stock,
			   TextoUbiLetra->GetValue().c_str(),
			   numero,
			   Prin->VerProveedor(a));
	
	//Ver si pasa la validación
	string errores = p.ValidarDatos(a);
	if (errores.size())
		wxMessageBox(errores);
	else{
		//Se agrega y guarda el producto
		Principal *Prin=Singleton::ObtenerInstancia();
		Prin->AgregarProducto(p);
		Prin->GuardarProductos();
		EndModal(1);
		
		
	}
}
}
VAgregar::~VAgregar() {
	
}

void VAgregar::ClickAyudaCargarProv( wxCommandEvent& event )  {
	ShellExecute(NULL,"open","AYUDA_AGREGARPROVEEDOR.png","AYUDA_AGREGARPROVEEDOR.png",NULL,SW_NORMAL); 
}

void VAgregar::ClickAyudaCargarProducto( wxCommandEvent& event )  {
	ShellExecute(NULL,"open","AYUDA_AGREGARPRODUCTO.png","AYUDA_AGREGARPRODUCTO.png",NULL,SW_NORMAL); 	
}

