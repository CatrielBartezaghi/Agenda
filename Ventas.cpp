
#include <string>
#include "Ventas.h"
#include "Producto.h"
#include <ctime>
#include <cstring>
#include <fstream>
#include "FAuxiliares.h"
#include <wx/string.h>

using namespace std;
//Constructores venta:
Venta::Venta(){}


Venta::Venta(Producto pro,int d, int m, int a, string nom, string tel, string dn, string otro, int can){
	producto=pro.vernombre();
	dia=d;
	mes=m;
	anio=a;
	nombre=nom;
	telefono=tel;
	DNI=dn;
	otro_dato=otro;
	precio_venta=pro.verprecio();
	cantidad=can;
}

//Métodos que retornan datos de venta
string Venta::verpro(){
	return producto;
}
;
int Venta::verdia(){
	return dia;
}
int Venta::vermes(){
	return mes;
}
int Venta::veranio(){
	return anio;
}
string Venta::vernom(){
	return nombre;
}
string Venta::vertel(){
	return telefono;
}
string Venta::verdni(){
	return DNI;
}
string Venta::verotro(){
	return otro_dato;
}
wxString Venta::verpre_venwx(){
	float asd = verpre_ven() * cantidad;
	wxString str;
	str=wxString()<<asd;
	str.Truncate(str.find(".")+3);
	return str;
}
float Venta::verpre_ven(){
	return precio_venta;
}
int Venta::vercantidad(){
	return cantidad;
}

//Métodos para modificar datos de venta
void Venta::modpro(Producto pro){
	producto=pro.vernombre();
}
void Venta::moddia(int d){
	dia=d;
}
void Venta::modmes(int m){
	mes=m;
}
void Venta::modanio(int a){
	anio=a;
}
void Venta::modnom (string nom){
	nombre=nom;
}
void Venta::modtel(string tel){
	telefono=tel;
}
void Venta::moddni(string dn){
	DNI=dn;
}
void Venta::modcan(int can){
	cantidad=can;
}
void Venta::modotro(string otro){
	otro_dato=otro;
}
//void Venta::modpre(float pre ){
//	precio_venta=pre;
//}

//Método para guardar venta
void Venta::GuardarVen(ofstream &archi){
	reg_venta reg;
	strcpy(reg.producto,producto.c_str());
	reg.dia=dia;
	reg.mes=mes;
	reg.anio=anio;
	strcpy(reg.nombre,nombre.c_str());
	strcpy(reg.telefono,telefono.c_str());
	strcpy(reg.DNI,DNI.c_str());
	strcpy(reg.otro_dato,otro_dato.c_str());
	reg.precio_venta=precio_venta;
	reg.cantidad=cantidad;
	
	archi.write(reinterpret_cast<char*>(&reg),sizeof(reg));	
}

//Metodos para leer venta
void Venta::LeerVen(ifstream &archi){
	reg_venta reg;
	archi.read(reinterpret_cast<char*>(&reg),sizeof(reg));
	producto=reg.producto;
	dia=reg.dia;
	mes=reg.mes;
	anio=reg.anio;
	nombre=reg.nombre;
	telefono=reg.telefono;
	DNI=reg.DNI;
	otro_dato=reg.otro_dato;
	precio_venta=reg.precio_venta;
	cantidad=reg.cantidad;
	
	
}

//Métodos de comparacion para orden la grilla de ventas
bool comparacion_producto_venta(Venta v1,Venta v2){
	string s1=v1.verpro();
	string s2=v2.verpro();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool comparacion_fecha_venta(Venta v1, Venta v2){
	if(v1.veranio()!=v2.veranio()){
		return v1.veranio()<v2.veranio();
	}
	if(v1.veranio()==v2.veranio()){
		if(v1.vermes()!=v2.vermes()){
			return v1.vermes()<v2.vermes();
		}
	}
	if(v1.veranio()==v2.veranio()){
		if(v1.vermes()==v2.vermes()){
			if(v1.verdia()!=v2.verdia()){
				return v1.verdia()<v2.verdia();
			}
		}
	}
	if(v1.veranio()==v2.veranio()){
		if(v1.vermes()==v2.vermes()){
			if(v1.vermes()==v2.vermes()){
				return v1.verdia();
			}
		}
	}
}
bool comparacion_nombre_venta(Venta v1,Venta v2){
	string s1=v1.vernom();
	string s2=v2.vernom();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool comparacion_telefono_venta(Venta v1, Venta v2){
	string s1=v1.vertel();
	string s2=v2.vertel();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
	
}
bool comparacion_dni_venta(Venta v1, Venta v2){
	string s1=v1.verdni();
	string s2=v2.verdni();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
	
}
bool comparacion_otro_dato_venta(Venta v1, Venta v2){
	string s1=v1.verotro();
	string s2=v2.verotro();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
	
}
bool comparacion_precio_venta(Venta v1, Venta v2){
	return (v1.verpre_ven()<v2.verpre_ven());
	
}
//Validación de datos escritos por el usuario
string Venta::ValidarDatosVenta(int a, int resta_stock, int cantidad){
	string errores;
	
	if(cantidad<=0) errores+= "El campo cantidad no puede ser 0 ni negativo\n";
	
	if(resta_stock<0) errores+= "No hay stock suficiente del producto seleccionado\n";
	
	if(nombre.size()==0) errores+="El campo nombre no puede estar vacio\n";
	
	if(nombre.size()>256) errores+="El nombre es demasiado largo\n";
	
	
	
	if (dia<0 || dia>31) errores+="El día debe estar entre 1 y 31, o vacio\n";
	if (mes<0 || mes>12) errores+="El mes debe estar entre 1 y 12, o vacio\n";
	if (anio!=0 && anio<=1900) errores+="El año no puede ser menor a 1900\n";
	
	return errores;
}
