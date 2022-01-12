#include "VVentaGrilla.h"
#include "Ventas.h"
#include "Principal.h"
#include "Singleton.h"
#include "VEditarVenta.h"
#include <wx/msgdlg.h>
#include "VPrincipal.h"
#include <windows.h>
VVentaGrilla::VVentaGrilla(wxWindow *parent) : MyDialog5(parent) {
	Principal *Prin=Singleton::ObtenerInstancia();
	int c_ven = Prin->cant_vent(); // Cantidad de ventas
	grilla_ven->AppendRows(c_ven); // Agregar tantas filas como registros
	for (int i=0;i<c_ven;i++) CargarFilasVen(i);// Cargar todos los datos
	grilla_ven->SetSelectionMode(wxGrid::wxGridSelectRows);
	SetTitle("Ventas");
}

void VVentaGrilla::CargarFilasVen(int i){
	//Cargar datos a la grilla
	Principal *Prin=Singleton::ObtenerInstancia();
	Venta &v=Prin->RetornarVenta(i);
	grilla_ven->SetCellValue(i,0,v.vernom());
	grilla_ven->SetCellValue(i,1,v.verdni());
	grilla_ven->SetCellValue(i,2,v.vertel());
	grilla_ven->SetCellValue(i,3,v.verotro());
	grilla_ven->SetCellValue(i,4,wxString()<<v.vercantidad()<<" X "<<v.verpro());
	grilla_ven->SetCellValue(i,5,v.verpre_venwx());
	grilla_ven->SetCellValue(i,6,(wxString()<<v.verdia()<<"/"<<wxString()<<v.vermes()<<"/"<<wxString()<<v.veranio()));
}
void VVentaGrilla::DobleClickGrillaVentas( wxGridEvent& event )  {
	int fila_actual = grilla_ven->GetGridCursorRow(); //Obtener el indice de venta
	VEditarVenta nueva_ventana(this,fila_actual); // Crear la ventana
	if (nueva_ventana.ShowModal()) //Mostrar
		CargarFilasVen(fila_actual); // Actualizar en la grilla
}

void VVentaGrilla::ClickGrillaVentas( wxGridEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	int columna=event.GetCol(), c_ven=Prin->cant_vent();
	//Ordenar segun el rotulo de la grilla seleccionado
	switch(columna) {
	case 0: Prin->OrdenarVenta(ORDEN_NOMBRE_VENTA); break;
	case 1: Prin->OrdenarVenta(ORDEN_DNI_VENTA); break;
	case 2: Prin->OrdenarVenta(ORDEN_TELEFONO_VENTA); break;
	case 3: Prin->OrdenarVenta(ORDEN_OTRO_DATO_VENTA); break;
	case 4: Prin->OrdenarVenta(ORDEN_PRODUCTO_VENTA); break;
	case 5: Prin->OrdenarVenta(ORDEN_PRECIO_VENTA); break;
	case 6: Prin->OrdenarVenta(ORDEN_FECHA_VENTA); break;
	}
	for (int i=0;i<c_ven;i++) CargarFilasVen(i);
}


VVentaGrilla::~VVentaGrilla() {
	
}

void VVentaGrilla::ElegirBusquedaVenta( wxCommandEvent& event )  {
	event.Skip();
}

void VVentaGrilla::EnterBuscarVenta( wxCommandEvent& event )  {
	ClickBuscarVenta(event);
}

void VVentaGrilla::ClickBuscarVenta( wxCommandEvent& event )  {
	Principal *Prin=Singleton::ObtenerInstancia();
	// Buscar desde la fila actual
	int fila_actual = grilla_ven->GetGridCursorRow();
	if (grilla_ven->GetSelectedRows().GetCount()==0) fila_actual=-1;
	int res=Prin->BuscarNombreVenta(BusquedaVentas->GetValue().c_str(),fila_actual+1,ChoiceVenta->GetSelection());
	// Si no encontro buscar otra vez desde el principio
	if (res==NO_SE_ENCUENTRA) 
		res=Prin->BuscarNombreVenta(BusquedaVentas->GetValue().c_str(),0,ChoiceVenta->GetSelection());
	if (res==NO_SE_ENCUENTRA) // Si no hay ninguna coincidencia
		wxMessageBox("No se encontraron coincidencias");
	else {
		grilla_ven->SetGridCursor(res,0); // Seleccionar
		grilla_ven->SelectRow(res); // Seleccionar
	}
}

void VVentaGrilla::ClickModificarVenta( wxCommandEvent& event )  {
	int fila_actual = grilla_ven->GetGridCursorRow();// Obtener el indice de Producto
	VEditarVenta nueva_ventana(this,fila_actual); // Crear la ventana
	if (nueva_ventana.ShowModal()){ // Mostrar
	CargarFilasVen(fila_actual); // Actualizar en la grilla
	
	}
}
void VVentaGrilla::ClickBotonCancelarVenta( wxCommandEvent& event )  {
	EndModal(0);
}

void VVentaGrilla::ClickEliminarVenta( wxCommandEvent& event )  {
	int fila_actual = grilla_ven->GetGridCursorRow(); //Copiar posicion del cursor en la grilla
	int res = wxMessageBox("Eliminar el registro?",grilla_ven->GetCellValue(fila_actual,0),wxYES_NO); //Preguntar al usuario si desea eliminar
	if (res==wxYES) {
		grilla_ven->DeleteRows(fila_actual,1);	//Eliminar fila 
		Principal *Prin=Singleton::ObtenerInstancia();
		Prin->EliminarVenta(fila_actual); //Eliminar venta
		Prin->GuardarVentas();
	}
}

void VVentaGrilla::ClickAyudaVentasGrilla( wxCommandEvent& event )  {
	ShellExecute(NULL,"open","AYUDA_VENTASGRILLA.png","AYUDA_VENTASGRILLA.png",NULL,SW_NORMAL); 	
}

