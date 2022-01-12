#include "VProveedores.h"
#include "Proveedor.h"
#include "Principal.h"
#include "Singleton.h"
#include "VAgregarProveedor.h"
#include "VPrincipal.h"
#include <wx/grid.h>
#include <wx/msgdlg.h>
#include "VEditarProveedor.h"
#include <windows.h>
VProveedores::VProveedores(wxWindow *parent) : MyDialog3(parent) {
	Principal *Prin=Singleton::ObtenerInstancia();
	int c_prov = Prin->cant_prov(); // Cantidad de proveedor
	grilla_prov->AppendRows(c_prov); // Agregar tantas filas como registros
	for (int i=0;i<c_prov;i++) CargarFilasProv(i);// Cargar todos los datos
	grilla_prov->SetSelectionMode(wxGrid::wxGridSelectRows);
	SetTitle("Proveedores");
	
}

VProveedores::~VProveedores() {
	
}

void VProveedores::ClickAgregarProveedor( wxCommandEvent& event )  {
	VAgregarProveedor nueva_ventana(this); //Crear ventana y mostrar
	if(nueva_ventana.ShowModal()==1){
		Principal *Prin=Singleton::ObtenerInstancia();
		grilla_prov->AppendRows(1); //Agregar fila en la grilla
		int pos_nuevo=Prin->cant_prov()-1;
		CargarFilasProv(pos_nuevo); //Copiar en grilla
		grilla_prov->SetGridCursor(pos_nuevo,0); //Seleccionar nuevo registro
		grilla_prov->SelectRow(pos_nuevo);
	}
}

void VProveedores::CargarFilasProv(int j){
	//Cargar datos en grilla
	Principal *Prin=Singleton::ObtenerInstancia();
	Proveedor &p=Prin->RetornarProveedor(j);
	grilla_prov->SetCellValue(j,0,p.vernom());
	grilla_prov->SetCellValue(j,1,p.vertel());
	grilla_prov->SetCellValue(j,2,p.verdir());
	grilla_prov->SetCellValue(j,3,p.verem());
	grilla_prov->SetCellValue(j,4,p.verotr());
		
}	
void VProveedores::EnterBuscarProveedor( wxCommandEvent& event )  {
	ClickBuscarProveedor(event);
}

void VProveedores::ClickBuscarProveedor( wxCommandEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	// Buscar desde la fila actual
	int fila_actual = grilla_prov->GetGridCursorRow();
	if (grilla_prov->GetSelectedRows().GetCount()==0) fila_actual=-1;
	int res=Prin->BuscarNombreProv(EscribirBusquedaProveedor->GetValue().c_str(),fila_actual+1);
	// Si no encontro buscar otra vez desde el principio
	if (res==NO_SE_ENCUENTRA) 
		res=Prin->BuscarNombreProv(EscribirBusquedaProveedor->GetValue().c_str(),0);
	if (res==NO_SE_ENCUENTRA) // Si no hay ninguna coincidencia
		wxMessageBox("No se encontraron coincidencias");
	else {
		grilla_prov->SetGridCursor(res,0); // Seleccionar
		grilla_prov->SelectRow(res); // Seleccionar
	}
}

void VProveedores::DobleClickGrillaProveedor( wxGridEvent& event )  {
	
	int fila_actual = grilla_prov->GetGridCursorRow(); // Obtener el indice de proveedor
	VEditarProveedor nueva_ventana(this,fila_actual); // Crear la ventana
	if (nueva_ventana.ShowModal()) // Mostrar y esperar
		CargarFilasProv(fila_actual); // Actualizar en la grilla

}

void VProveedores::ClickGrillaProveedor( wxGridEvent& event )  {
	
	Principal *Prin=Singleton::ObtenerInstancia();
	
	//Ordenar de acuerdo al rotulo de la tabla seleccionado
	int columna=event.GetCol(), c_prov=Prin->cant_prov();
	switch(columna) { 
	case 0: Prin->OrdenarProveedor(ORDEN_NOMBRE_PROVEEDOR); break;
	case 1: Prin->OrdenarProveedor(ORDEN_TELEFONO_PROVEEDOR); break;
	case 2: Prin->OrdenarProveedor(ORDEN_DIRECCION_PROVEEDOR); break;
	case 3: Prin->OrdenarProveedor(ORDEN_EMAIL_PROVEEDOR); break;
	case 4: Prin->OrdenarProveedor(ORDEN_OTRO_PROVEEDOR); break;
	}
	for (int i=0;i<c_prov;i++) CargarFilasProv(i);
	
}

void VProveedores::ClickModificarProveedor( wxCommandEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	if(Prin->cant_prov()==0){
		wxMessageBox("No has cargado ningun proveedor aun!");
	}else{
	int fila_actual = grilla_prov->GetGridCursorRow();// obtener el indice de persona
	VEditarProveedor nueva_ventana(this,fila_actual); // crear la ventana
	if (nueva_ventana.ShowModal()) // mostrar y esperar
		CargarFilasProv(fila_actual); // actualizar en la grilla
}
}
void VProveedores::ClickCancelarProveedor( wxCommandEvent& event )  {
	EndModal(0);
}

void VProveedores::ClickEliminarProveedor( wxCommandEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	if(Prin->cant_prov()==0){
		wxMessageBox("No has cargado ningun proveedor aun!");
	}else{
	int fila_actual = grilla_prov->GetGridCursorRow(); //Copiar posición del cursor
	int res = wxMessageBox("Eliminar el registro?",grilla_prov->GetCellValue(fila_actual,0),wxYES_NO); //Preguntar al ususario si desea eliminar
	if (res==wxYES) {
		grilla_prov->DeleteRows(fila_actual,1); //Eliminar fila
		Principal *Prin=Singleton::ObtenerInstancia();
		Prin->EliminarProveedor(fila_actual); //Eliminar de base de datos
		Prin->GuardarProveedores();
	}
}
}
void VProveedores::ClickAyudaGrillaProveedor( wxCommandEvent& event )  {
	ShellExecute(NULL,"open","AYUDA_PROVEEDOR.png","AYUDA_PROVEEDOR.png",NULL,SW_NORMAL); 	
}

