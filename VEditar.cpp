#include "VEditar.h"
#include "Producto.h"
#include "Singleton.h"
#include "Principal.h"
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <windows.h>
VEditar::VEditar(wxWindow *parent, int cual) : MyDialog1(parent) {
	
	//Se cargan los datos actuales del producto en la ventana
	indice_producto=cual;
	Principal *Prin=Singleton::ObtenerInstancia(); 
	Producto &p=(*Prin)[cual];
	TextoNombre->SetValue(p.vernombre());
	TextoPrecio->SetValue(p.verpreciowx());
//	TextoPrecio->SetValue(wxString()<<wxString().Printf("%d",p.verprecio()));
	TextoCategoria->SetValue(p.vercategoria());
	TextoStock->SetValue(wxString()<<p.verstock());
	TextoUbiLetra->SetValue(p.verubicacion().letra);
	TextoUbiNumero->SetValue(wxString()<<p.verubicacion().numero);
	boton1->SetLabel("Volver");
	boton2->SetLabel("Guardar");
	SetTitle("Editar Producto");
	
	//Se cargar los proveedor guardados
	for(size_t i=0;i<Prin->cant_prov();i++) {
		EleccionProveedor->Append(Prin->VerProveedor(i).vernom().c_str());
	}
	
	//Se selecciona el proveedor que estaba asigando
	indice_proveedor=EleccionProveedor->FindString(Prin->VerProducto(cual).verproveedor());
	EleccionProveedor->Select(indice_proveedor);
	if(indice_proveedor>500 || indice_proveedor<0){
	indice_proveedor=0;
	EleccionProveedor->Select(indice_proveedor);
	}

}

void VEditar::ClickBoton1( wxCommandEvent& event )  {
	EndModal(0);
}

void VEditar::ClickBoton2( wxCommandEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	
	//Convertir cadenas a números
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
			   Prin->VerProveedor(indice_proveedor));
	
	//Ver si pasa la validación
	string errores = p.ValidarDatos(indice_proveedor);
	if (errores.size()) // ver si no pasa la validacion
		wxMessageBox(errores);
	else{
		//Se reemplaza el producto editado y se guarda el archivo
		Principal *Prin=Singleton::ObtenerInstancia();
		(*Prin)[indice_producto]=p;
		Prin->GuardarProductos();
		EndModal(1);
		
		
	}
}

void VEditar::ElegirProveedor( wxCommandEvent& event )  {
	//Se guarda el índice del proveedor elegido
	indice_proveedor=EleccionProveedor->GetSelection();
}


VEditar::~VEditar() {
	
}

void VEditar::ClickAyudaCargarProv( wxCommandEvent& event )  {
	ShellExecute(NULL,"open","AYUDA_AGREGARPROVEEDOR.png","AYUDA_AGREGARPROVEEDOR.png",NULL,SW_NORMAL); 	
}

void VEditar::ClickAyudaCargarProducto( wxCommandEvent& event )  {
	ShellExecute(NULL,"open","AYUDA_AGREGARPRODUCTO.png","AYUDA_AGREGARPRODUCTO.png",NULL,SW_NORMAL); 	
}

