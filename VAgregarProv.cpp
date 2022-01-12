#include "VAgregarProv.h"
#include "Proveedor.h"
#include <wx/msgdlg.h>
VAgregarProv::VAgregarProv(wxWindow *parent) : MyDialog2(parent) {
	SetTitle("Agregar Proveedor"); 
	boton1->SetLabel("Cancelar"); 
	boton2->SetLabel("Agregar");
}

void VAgregarProv::ClickBoton1( wxCommandEvent& event )  {
	EndModal(0);
}

void VAgregarProv::ClickBoton2( wxCommandEvent& event )  {
	Proveedor p(TextoNombre->GetValue().c_str(),
				TextoTelefono->GetValue().c_str(),
				TextoDireccion->GetValue().c_str(),
				TextoEmail->GetValue().c_str(),
				TextoOtroContacto->GetValue().c_str());
}

VAgregarProv::~VAgregarProv() {
	
}

int VAgregarProv::VerCual(  )  {
	
	return cual2;
}

