#include "Producto.h"
#include <string>
#include <cstring>
#include "Proveedor.h"
#include "FAuxiliares.h"
#include <fstream>
#include "Singleton.h"
#include <iomanip>
#include <wx/string.h>
#include <wx/msgdlg.h>
using namespace std;
//Constructores
Producto::Producto(){}

Producto::Producto(string _nombre, float _precio, string _categoria, int _stock, ubicacion _b, Proveedor provee ){
	nombre=_nombre;
	precio=_precio;
	categoria=_categoria;
	stock=_stock;
	b=_b;
	prov=provee.vernom();
}

Producto::Producto(string _nombre, float _precio, string _categoria, int _stock, string _letra, int _num, Proveedor provee){
	nombre=_nombre;
	precio=_precio;
	categoria=_categoria;
	stock=_stock;
	b.letra=_letra;
	b.numero=_num;
	prov=provee.vernom();
}
//Metodos de retorno de datos de producto:
string Producto::vernombre(){
	return nombre;
}
float Producto::verprecio(){
	return precio;
}
wxString Producto::verpreciowx(){
	
	
	wxString str;
	
	str=wxString()<<precio;

	str.Truncate(str.find(".")+3);

	
	return str;
}
string Producto::vercategoria(){
	return categoria;
}
int Producto::verstock(){
	return stock;
}
ubicacion Producto::verubicacion(){
	return b;
}
string Producto::verproveedor(){
	return prov;
}
//Metodos para modificar datos de producto
void Producto::mod_nom(string nom){
	nombre=nom;
}
void Producto::mod_pre(float pre){
	precio=pre;
}
void Producto::mod_cat(string cat){
	categoria=cat;
}
void Producto::mod_sto(int sto){
	stock=sto;
}
void Producto::mod_ubi(ubicacion ubi){
	b=ubi;
}
void Producto::mod_pro(Proveedor pr){
	prov=pr.vernom();
}
//Metodo para guardar producto
void Producto::GuardarProd(ofstream &archi){
	reg_prod reg;
	strcpy(reg.nombre,nombre.c_str());
	reg.precio=precio;
	strcpy(reg.categoria,categoria.c_str());
	reg.stock=stock;
	strcpy(reg.b2.letra,b.letra.c_str());
	reg.b2.numero=b.numero;
	strcpy(reg.prov,prov.c_str());
	archi.write(reinterpret_cast<char*>(&reg),sizeof(reg));
}
//Metodo para leer producto;
void Producto::LeerProd(ifstream &archi){
	reg_prod reg;
	archi.read(reinterpret_cast<char*>(&reg),sizeof(reg));
	nombre=reg.nombre;
	precio=reg.precio;
	categoria=reg.categoria;
	stock=reg.stock;
	b.letra=reg.b2.letra;
	b.numero=reg.b2.numero;
	prov=reg.prov;
	
}
//Metodos de comparacion para ordenar en la grilla
bool comparacion_nombre( Producto p1, Producto p2){
	string s1=p1.vernombre();
	string s2=p2.vernombre();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool comparacion_precio(Producto p1, Producto p2){
	return (p1.verprecio()<p2.verprecio());
}
bool comparacion_categoria(Producto p1, Producto p2){
	string s1=p1.vercategoria();
	string s2=p2.vercategoria();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool comparacion_stock(Producto p1, Producto p2){
	return(p1.verstock()<p2.verstock());
}
bool comparacion_letra(Producto p1, Producto p2){
	string s1=p1.verubicacion().letra;
	string s2=p2.verubicacion().letra;
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
bool comparacion_numero(Producto p1, Producto p2){
	return (p1.verubicacion().numero<p2.verubicacion().numero);
}
bool comparacion_proveedor(Producto p1, Producto p2){
	string s1=p1.verproveedor();
	string s2=p2.verproveedor();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}
//Método para alertar al usuario si algun campo esta incompleto al agregar un producto
string Producto::ValidarDatos(int a){
string errores;

Principal *Prin=Singleton::ObtenerInstancia();
if(Prin->cant_prov()==0) errores+="Aun no se ha añadido ningun proveedor!";

if(nombre.size()==0) errores+="El campo nombre no puede estar vacio\n";
if(nombre.size()>256) errores+="El nombre es demasiado largo\n";

if(precio<0) errores+="El precio no puede ser negativo\n";
if(precio>2147483647) errores+="El precio es demasiado grande\n";


if(categoria.size()>256) errores+="La categoría es demasiado larga\n";

if(stock<0) errores+="El stock no puede ser negativo\n";
if(stock>2147483647) errores+="El stock es demasiado grande\n";


if(b.letra.size()>256) errores+="Demasiadas letras para la ubicación\n";


if(b.numero>2147483647) errores+="El número es demasiado grande\n";



return errores;
}


