
#include "Proveedor.h"
#include <cstring>
#include <fstream>
#include "FAuxiliares.h"
using namespace std;

//Constructores Proveedor
Proveedor::Proveedor(){}

Proveedor::Proveedor(string nom, string tel, string dir, string em,string otro){
	nombre=nom;
	telefono=tel;
	direccion=dir;
	email=em;
	otro_contacto=otro;
}
//Métodos de retorno de datos de proveedores:
string Proveedor::vernom(){
	return nombre;
}
string  Proveedor::vertel(){
	return telefono;
}
string Proveedor::verdir(){
	return direccion;
}
string Proveedor::verem(){
	return email;
}
string Proveedor::verotr(){
	return otro_contacto;
}

//Métodos para modificar dator de proveedor:
void Proveedor::modnom(string nomb){
	nombre=nomb;
}
void Proveedor::modtel(string tele){
	telefono=tele;
}
void Proveedor::moddir(string dire){
	direccion=dire;
}
void Proveedor::modem(string ema){
	email=ema;
}	
void Proveedor::modotro(string otro){
	otro_contacto=otro;
}

//Método para guardar un proveedor
void Proveedor::GuardarProv(ofstream &archi){
	reg_proov reg;
	strcpy(reg.nombre,nombre.c_str());
	strcpy(reg.telefono,telefono.c_str());
	strcpy(reg.direccion,direccion.c_str());
	strcpy(reg.email,email.c_str());
	strcpy(reg.otro_contacto,otro_contacto.c_str());
	
	archi.write(reinterpret_cast<char*>(&reg),sizeof(reg));	
}
//Método para leer un proveedor
void Proveedor::LeerProv(ifstream &archi){
	reg_proov reg;
	archi.read(reinterpret_cast<char*>(&reg),sizeof(reg));
	nombre=reg.nombre;
	telefono=reg.telefono;
	direccion=reg.direccion;
	email=reg.email;
	otro_contacto=reg.otro_contacto;
	
	
}
//Metodos de comparacion para ordenar en la grilla
bool comparacion_nombre_prov(Proveedor p1, Proveedor p2){
	string s1=p1.vernom();
	string s2=p2.vernom();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool comparacion_telefono_prov(Proveedor p1, Proveedor p2){
	string s1=p1.vertel();
	string s2=p2.vertel();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool comparacion_direccion_prov(Proveedor p1, Proveedor p2){
	string s1=p1.verdir();
	string s2=p2.verdir();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool comparacion_email_prov(Proveedor p1, Proveedor p2){
	string s1=p1.verem();
	string s2=p2.verem();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}

bool comparacion_otro_contacto_prov(Proveedor p1, Proveedor p2){
	string s1=p1.verotr();
	string s2=p2.verotr();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
//Método para alertar al usuario si algun campo esta incompleto al agregar un producto
string Proveedor::ValidarDatos(){
	string errores;
	if(nombre.size()==0) errores+="El campo nombre no puede estar vacio\n";
	if(nombre.size()>256) errores+="El nombre es demasiado largo\n";
	
	if(telefono.size()>256) errores+="El telefono es demasiado largo\n";
	
	if(direccion.size()>256) errores+="La direccion es demasiada larga\n";
	
	if(email.size()>256) errores+="El email es demasiado largo\n";
	
	if(otro_contacto.size()>256) errores+="El contacto es demasiado largo\n";
	
	return errores;
	
	
}

