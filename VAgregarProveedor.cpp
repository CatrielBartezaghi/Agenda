#include "VAgregarProveedor.h"
#include "Principal.h"
#include "Singleton.h"
#include <wx/msgdlg.h>
#include <windows.h>
VAgregarProveedor::VAgregarProveedor(wxWindow *parent) : MyDialog11(parent) {
	//Rotulos ventana agregar proveedor
	SetTitle("Agregar Proveedor");
	boton1->SetLabel("Cancelar");
	boton2->SetLabel("Aceptar");
	BotonAyudaCargarProv->SetLabel("Ayuda");
}

void VAgregarProveedor::ClickBoton1( wxCommandEvent& event )  {
	EndModal(0);
}

void VAgregarProveedor::ClickBoton2( wxCommandEvent& event )  {
	
	//Se convierten y pasan los datos escritos por el usuario
	Proveedor p(TextoNombre->GetValue().c_str(),
				TextoTelefono->GetValue().c_str(),
				TextoDireccion->GetValue().c_str(),
				TextoEmail->GetValue().c_str(),
				TextoOtroCotacto->GetValue().c_str());
	
	//Ver si pasa la validación
	string errores=p.ValidarDatos();
	if(errores.size())
		wxMessageBox(errores);
	else{
		
		//Guardar proveedor
		Principal *Prin=Singleton::ObtenerInstancia();
		Prin->AgregarProveedor(p);
		Prin->GuardarProveedores();
		EndModal(1);
		
	}

}

VAgregarProveedor::~VAgregarProveedor() {
	
}

void VAgregarProveedor::ClickAyudaCargarProv( wxCommandEvent& event )  {
	ShellExecute(NULL,"open","AYUDA_AGREGARPROVEEDOR.png","AYUDA_AGREGARPROVEEDOR.png",NULL,SW_NORMAL); 	
}

