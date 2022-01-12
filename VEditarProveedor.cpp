#include "VEditarProveedor.h"
#include "Proveedor.h"
#include "Principal.h"
#include "Singleton.h"
#include <wx/msgdlg.h>
#include <windows.h>
VEditarProveedor::VEditarProveedor(wxWindow *parent, int cual) : MyDialog11(parent) {
	
	//Se cargan los datos del proveedor a editar
	indice_proveedor=cual;
	Principal *Prin=Singleton::ObtenerInstancia(); // obtener el puntero a la unica instancia posible de Agenda
	Proveedor &p=Prin->RetornarProveedor(cual);
	TextoNombre->SetValue(p.vernom());
	TextoTelefono->SetValue(p.vertel());
	TextoDireccion->SetValue(p.verdir());
	TextoEmail->SetValue(p.verem());
	TextoOtroCotacto->SetValue(p.verotr());
	boton1->SetLabel("Volver");
	boton2->SetLabel("Guardar");
	BotonAyudaCargarProv->SetLabel("Ayuda");
	SetTitle("Editar Proveedor");
}

void VEditarProveedor::ClickBoton1( wxCommandEvent& event )  {
	EndModal(0);
}

void VEditarProveedor::ClickBoton2( wxCommandEvent& event )  {
	
	//Se convierten y pasan los datos nuevos
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
		//Se guarda y reemplaza
		Principal *Prin=Singleton::ObtenerInstancia();
		Prin->ReemplazarProveedor(p,indice_proveedor);
		Prin->GuardarProveedores();
		EndModal(1);
	}
}
VEditarProveedor::~VEditarProveedor() {
	
}

void VEditarProveedor::ClickAyudaCargarProv( wxCommandEvent& event )  {
	ShellExecute(NULL,"open","AYUDA_AGREGARPROVEEDOR.png","AYUDA_AGREGARPROVEEDOR.png",NULL,SW_NORMAL); 	
}

