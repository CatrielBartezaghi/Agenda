#include "VPrincipal.h"
#include "Principal.h"
#include <wx/string.h>
#include "Producto.h"
#include "Singleton.h"
#include "VAgregar.h"
#include "VAgregarProveedor.h"
#include "VProveedores.h"
#include "VEditar.h"
#include <wx/grid.h>
#include <wx/msgdlg.h>
#include <iomanip>
#include "VVenta.h"
#include "VVentaGrilla.h"
#include <cstdio>
#include <windows.h>
#include "Icono.xpm"
#include <wx/icon.h>
VPrincipal::VPrincipal(wxWindow *parent) : FBMainWindow(parent) {
	SetIcon(wxIcon(Icono_xpm));
	Principal *Prin=Singleton::ObtenerInstancia();
	int c_pers = Prin->cant_prod(); // Cantidad de productos
	grilla->AppendRows(c_pers); // Agregar tantas filas como registros
	for (int i=0;i<c_pers;i++) CargarFilasProd(i);// Cargar todos los datos
	grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
	Show(); // Mostrar la ventana
}
void VPrincipal::CargarFilasProd(int i){
	//Cargar datos en las celdas
	Principal *Prin=Singleton::ObtenerInstancia();
	Producto &p=(*Prin)[i]; 
	grilla->SetCellValue(i,0,p.vernombre());
	grilla->SetCellValue(i,1,p.verpreciowx());
	grilla->SetCellValue(i,2,p.vercategoria());
	grilla->SetCellValue(i,3,wxString()<<p.verstock());
	grilla->SetCellValue(i,4,p.verubicacion().letra);
	grilla->SetCellValue(i,5,wxString()<<p.verubicacion().numero);
	grilla->SetCellValue(i,6,p.verproveedor());
}

void VPrincipal::DobleClickGrilla( wxGridEvent& event )  {
	
	int fila_actual = grilla->GetGridCursorRow(); // Obtener el indice de producto
	VEditar nueva_ventana(this,fila_actual); // Crear la ventana
	if (nueva_ventana.ShowModal()) // Mostrar y esperar
		CargarFilasProd(fila_actual); // Actualizar en la grilla

}

void VPrincipal::ClickGrilla( wxGridEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	//Ordenar de acuerdo al rotulo de la tabla seleccionado
	int columna=event.GetCol(), c_pers=Prin->cant_prod();
	switch(columna) { 
	case 0: Prin->Ordenar(ORDEN_NOMBRE); break;
	case 1: Prin->Ordenar(ORDEN_PRECIO); break;
	case 2: Prin->Ordenar(ORDEN_CATEGORIA); break;
	case 3: Prin->Ordenar(ORDEN_STOCK); break;
	case 4: Prin->Ordenar(ORDEN_LETRA); break;
	case 5: Prin->Ordenar(ORDEN_NUMERO); break;
	case 6: Prin->Ordenar(ORDEN_PROVEEDOR); break;
	}
	for (int i=0;i<c_pers;i++) CargarFilasProd(i); // Actualizar vista
}
	


void VPrincipal::ClickAgregar( wxCommandEvent& event )  {
	
	VAgregar nueva_ventana(this); //Crear ventana
	if(nueva_ventana.ShowModal()==1){ //Mostrar
		Principal *Prin=Singleton::ObtenerInstancia();
		grilla->AppendRows(1); //Agregar un lugar en la grilla
		int pos_nuevo=Prin->cant_prod()-1;
		CargarFilasProd(pos_nuevo); //Copiar en grilla
		grilla->SetGridCursor(pos_nuevo,0); //Seleccionar nuevo registro
		grilla->SelectRow(pos_nuevo);
	}
}
void VPrincipal::ClickModificar( wxCommandEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	if(Prin->cant_prod()==0){
		wxMessageBox("No has cargado ningun producto aun!");
	}else{
	int fila_actual = grilla->GetGridCursorRow();// obtener el indice de Producto
	VEditar nueva_ventana(this,fila_actual); // Crear la ventana
	if (nueva_ventana.ShowModal()) // Mostrar y esperar
		CargarFilasProd(fila_actual); // Actualizar en la grilla
}
}
void VPrincipal::ClickVender( wxCommandEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	if(Prin->cant_prod()==0){
		wxMessageBox("No has cargado ningun producto aun!");
	}else{
	int fila_actual=grilla->GetGridCursorRow();
	VVenta nueva_ventana(this,grilla->GetGridCursorRow()); //Mostrar ventana y pasar posicion del cursor
	if(nueva_ventana.ShowModal()){ //Mostrar ventana
	CargarFilasProd(fila_actual);
	}
}
}
VPrincipal::~VPrincipal() {
	
}

void VPrincipal::ClickBuscar( wxCommandEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	// Buscar desde la fila actual
	int fila_actual = grilla->GetGridCursorRow();
	if (grilla->GetSelectedRows().GetCount()==0) fila_actual=-1;
	int res=Prin->BuscarNombre(EscribirBusqueda->GetValue().c_str(),fila_actual+1);
	// Si no encontro buscar otra vez desde el principio
	if (res==NO_SE_ENCUENTRA) 
		res=Prin->BuscarNombre(EscribirBusqueda->GetValue().c_str(),0);
	if (res==NO_SE_ENCUENTRA) // Si no hay ninguna coincidencia
		wxMessageBox("No se encontraron coincidencias");
	else {
		grilla->SetGridCursor(res,0); // Seleccionar
		grilla->SelectRow(res); // Seleccionar
	}
}

void VPrincipal::EnterBuscar( wxCommandEvent& event )  {
	ClickBuscar(event);
}
void VPrincipal::ClickProveedores( wxCommandEvent& event )  {
	
	VProveedores nueva_ventana(this);
	nueva_ventana.ShowModal();
	
}

void VPrincipal::ClickEliminar( wxCommandEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	if(Prin->cant_prod()==0){
		wxMessageBox("No has cargado ningun producto aun!");
	}else{
	int fila_actual = grilla->GetGridCursorRow(); //Copiar ubicacion del cursor
	int res = wxMessageBox("Eliminar el registro?",grilla->GetCellValue(fila_actual,0),wxYES_NO); //Preguntar al usario si desea elminar
	if (res==wxYES) {
		grilla->DeleteRows(fila_actual,1); //Borrar fila en la grilla
		Principal *Prin=Singleton::ObtenerInstancia();
		Prin->EliminarProducto(fila_actual); //Eliminar de la base de datos
		Prin->GuardarProductos();
	}
}
}

void VPrincipal::ClickVentas( wxCommandEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	if(Prin->cant_vent()==0){
		wxMessageBox("No has realizado ninguna venta aun!");
	}else{
	VVentaGrilla nueva_ventana;
	if(nueva_ventana.ShowModal()){
		Principal *Prin=Singleton::ObtenerInstancia();
		int c_pers = Prin->cant_prod(); // Cantidad de productos
		for (int i=0;i<c_pers;i++) CargarFilasProd(i);// Cargar todos los datos
		grilla->SetSelectionMode(wxGrid::wxGridSelectRows);	
	}
}
}
void VPrincipal::ClickAyudaPrincipal( wxCommandEvent& event )  {
	ShellExecute(NULL,"open","AYUDA_PRINCIPAL.png","AYUDA_PRINCIPAL.png",NULL,SW_NORMAL);
}

