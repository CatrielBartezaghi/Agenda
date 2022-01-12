#include "Principal.h"
#include "Producto.h"
#include "Proveedor.h"
#include <algorithm>
#include <vector>
#include "FAuxiliares.h"
#include <fstream>

using namespace std;


Principal::Principal(){
// Se leen los productos y se los coloca en el vector
	ifstream archivo_productos(nombreArchivoProductos.c_str(),ios::binary|ios::ate);
	if (archivo_productos.is_open()) {
		int tamanio_archivo = archivo_productos.tellg();
		int cantidad_proyectos = tamanio_archivo/sizeof(reg_prod);
		V.resize(cantidad_proyectos);
		archivo_productos.seekg(0,ios::beg);
		for (int i=0;i<cantidad_proyectos;i++)
			V[i].LeerProd(archivo_productos);
		archivo_productos.close();
	}

// Se leen los proveedor y se los coloca en el vector
	ifstream archivo_proveedores(nombreArchivoProveedores.c_str(),ios::binary|ios::ate);
	if (archivo_proveedores.is_open()) {
		int tamanio_archivo = archivo_proveedores.tellg();
		int cantidad_eventos = tamanio_archivo/sizeof(reg_proov);
		U.resize(cantidad_eventos);
		archivo_proveedores.seekg(0,ios::beg);
		for (int i=0;i<cantidad_eventos;i++)
			U[i].LeerProv(archivo_proveedores);
		archivo_proveedores.close();
		
	}
// Se leen las ventas y se las coloca en el vector
	ifstream archivo_ventas(nombreArchivoVentas.c_str(),ios::binary|ios::ate);
	if (archivo_ventas.is_open()) {
		int tamanio_archivo = archivo_ventas.tellg();
		int cantidad_eventos = tamanio_archivo/sizeof(reg_venta);
		W.resize(cantidad_eventos);
		archivo_ventas.seekg(0,ios::beg);
		for (int i=0;i<cantidad_eventos;i++)
			W[i].LeerVen(archivo_ventas);
		archivo_ventas.close();
	}
}
//Se guardan guardan los productos
bool Principal::GuardarProductos(){
	ofstream archivo(nombreArchivoProductos.c_str(),ios::binary|ios::ate);
	if(!archivo.is_open()){
	return false;
	}
	int cantprod=cant_prod();
	for(int i=0;i<cantprod;i++) { 
	V[i].GuardarProd(archivo);
	}
	archivo.close();
	return true;
		
}
//Se guardan guardan los proveedores
bool Principal::GuardarProveedores(){
	ofstream archivo(nombreArchivoProveedores.c_str(),ios::binary|ios::ate);
	if(!archivo.is_open()){
		return false;
	}
	int cantprov=cant_prov();
	for(int i=0;i<cantprov;i++) { 
		U[i].GuardarProv(archivo);
	}
	archivo.close();
	return true;
}
//Se guardan guardan las ventas
bool Principal::GuardarVentas(){
	ofstream archivo(nombreArchivoVentas.c_str(),ios::binary|ios::ate);
	if(!archivo.is_open()){
		return false;
	}
	int cantvent=cant_vent();
	for(int i=0;i<cantvent;i++) { 
		W[i].GuardarVen(archivo);
	}
	archivo.close();
	return true;
}	

//Funciones de retorno de valores:
int Principal::cant_prod(){
	return V.size();
}

int Principal::cant_prov(){
	return U.size();
}
int Principal::cant_vent(){
	return W.size();
}
Producto &Principal::operator[](int i) {
	return V[i];
}
Proveedor &Principal::RetornarProveedor(int j){
	return U[j];
}
Venta &Principal::RetornarVenta(int i){
	return W[i];
}
Producto &Principal::VerProducto(int i) {
	return V[i];
}
Proveedor &Principal::VerProveedor(int i){
	return U[i];
}
Venta &Principal::VerVenta(int i){
	return W[i];
}
void Principal::AgregarProducto(Producto &p){
	V.push_back(p);
}
void Principal::AgregarProveedor(Proveedor &p){
	U.push_back(p);
}
void Principal::AgregarVenta(Venta &v){
	W.push_back(v);
}
void Principal::ReemplazarProveedor(Proveedor &p, int pos){
	U[pos]=p;
}
void Principal::ReemplazarVenta(Venta &v, int pos){
	W[pos]=v;
}

// Orden de Productos
void Principal::Ordenar(CriterioOrden criterio){
	switch(criterio){
	case ORDEN_NOMBRE:
		sort(V.begin(),V.end(),comparacion_nombre);
		break;
	case ORDEN_PRECIO:
		sort(V.begin(),V.end(),comparacion_precio);
		break;
	case ORDEN_CATEGORIA:
		sort(V.begin(),V.end(),comparacion_categoria);
		break;
	case ORDEN_STOCK:
		sort(V.begin(),V.end(),comparacion_stock);
		break;
	case ORDEN_LETRA:
		sort(V.begin(),V.end(),comparacion_letra);
		break;
	case ORDEN_NUMERO:
		sort(V.begin(),V.end(),comparacion_numero);
		break;
	case ORDEN_PROVEEDOR:
		sort(V.begin(),V.end(),comparacion_proveedor);
		break;
	}
}
//Orden de Proveedores
void Principal::OrdenarProveedor(CriterioOrdenProveedor criterio){
	switch(criterio){
	case ORDEN_NOMBRE_PROVEEDOR:
		sort(U.begin(),U.end(),comparacion_nombre_prov);
		break;
	case ORDEN_TELEFONO_PROVEEDOR:
		sort(U.begin(),U.end(),comparacion_telefono_prov);
		break;
	case ORDEN_DIRECCION_PROVEEDOR:
		sort(U.begin(),U.end(),comparacion_direccion_prov);
		break;
	case ORDEN_EMAIL_PROVEEDOR:
		sort(U.begin(),U.end(),comparacion_email_prov);
		break;
	case ORDEN_OTRO_PROVEEDOR:
		sort(U.begin(),U.end(),comparacion_otro_contacto_prov);
		break;
	}
}
//Orden de ventas
void Principal::OrdenarVenta(CriterioOrdenVenta criterio){
	switch(criterio){
	case ORDEN_PRODUCTO_VENTA:
		sort(W.begin(),W.end(),comparacion_producto_venta);
		break;
	case ORDEN_FECHA_VENTA:
		sort(W.begin(),W.end(),comparacion_fecha_venta);
		break;
	case ORDEN_NOMBRE_VENTA:
		sort(W.begin(),W.end(),comparacion_nombre_venta);
		break;
	case ORDEN_TELEFONO_VENTA:
		sort(W.begin(),W.end(),comparacion_telefono_venta);
		break;
	case ORDEN_DNI_VENTA:
		sort(W.begin(),W.end(),comparacion_dni_venta);
		break;
	case ORDEN_OTRO_DATO_VENTA:
		sort(W.begin(),W.end(),comparacion_otro_dato_venta);
		break;
	case ORDEN_PRECIO_VENTA:
		sort(W.begin(),W.end(),comparacion_precio_venta);
		break;
	}
	
}
//Metodos para eliminar
void Principal::EliminarProducto(int i){
	V.erase(V.begin()+i);
}

void Principal::EliminarProveedor(int i){
	U.erase(U.begin()+i);
}
void Principal::EliminarVenta(int i){
	W.erase(W.begin()+i);
}
//Busqueda de producto por nombre
int Principal::BuscarNombre(string parte, int pos_desde){
	pasar_a_minusculas(parte);
	int cant = cant_prod();
	for (int i=pos_desde;i<cant;i++) {
		Producto &p = V[i];
		string nombre=p.vernombre();
		pasar_a_minusculas(nombre);
		if (nombre.find(parte,0)!=string::npos)
			return i;
	}
	return NO_SE_ENCUENTRA;
}
//Busqueda de proveedor por nombre
int Principal::BuscarNombreProv(string parte, int pos_desde){
	pasar_a_minusculas(parte);
	int cant = cant_prov();
	for (int i=pos_desde;i<cant;i++) {
		Proveedor &p = U[i];
		string nombre=p.vernom();
		pasar_a_minusculas(nombre);
		if (nombre.find(parte,0)!=string::npos)
			return i;
	}
	return NO_SE_ENCUENTRA;
}
//Busqueda de venta por nombre o producto 
int Principal::BuscarNombreVenta(string parte, int pos_desde,int criteriobusqueda){
	pasar_a_minusculas(parte);
	int cant = cant_vent();
	for (int i=pos_desde;i<cant;i++) {
		Venta &v = W[i];
		if(criteriobusqueda==0){
			string nombre=v.vernom();
			pasar_a_minusculas(nombre);
			if (nombre.find(parte,0)!=string::npos)
				return i;
		}else{
			string nombre=v.verpro();
			pasar_a_minusculas(nombre);
			if (nombre.find(parte,0)!=string::npos)
				return i;	
		}
	}
	return NO_SE_ENCUENTRA;
}

