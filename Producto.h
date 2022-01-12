#ifndef NO SE_H
#define NO SE_H
#include <string>
#include <fstream>
#include <ctime>
#include "Proveedor.h"
#include "Producto.h"
#include <wx/string.h>
using namespace std;
struct ubicacion{
	string letra;
	int numero;
	
};
struct ubicacion2{
	char letra[50];
	int numero;
};
struct reg_prod{
	char nombre[256];
	float precio;
	char categoria[256];
	int stock;
	ubicacion2 b2;
	char prov[256];
};
struct cambio_precio{
	int dd; 
	int mm;
	int aa;
	float nuevoprecio;
	
};


class Producto{
private:	
	string nombre;
	float precio;;  
	string categoria;
	int stock;
	ubicacion b;
	string prov;
public:
	Producto();
	Producto(string _nombre, float _precio, string _categoria, int _stock, ubicacion _b, Proveedor provee);
	Producto(string _nombre, float _precio, string _categoria, int _stock, string _letra, int _num, Proveedor provee);
	string vernombre();
	wxString verpreciowx();
	float verprecio();
	string vercategoria();
	int verstock();
	ubicacion verubicacion();
	string verproveedor();
	void mod_nom(string nom);
	void mod_pre(float pre);
	void mod_cat(string cat);
	void mod_sto(int sto);
	void mod_ubi(ubicacion ubi);
	void mod_pro(Proveedor pr);
	
	
	void GuardarProd(ofstream &archi);
	
	void LeerProd(ifstream &archi);
	
	string ValidarDatos(int a);
	
	
};


	bool comparacion_nombre(Producto p1,Producto p2);
	bool comparacion_precio(Producto p1, Producto p2);
	bool comparacion_categoria(Producto p1, Producto p2);
	bool comparacion_stock(Producto p1, Producto p2);
	bool comparacion_letra(Producto p1, Producto p2);
	bool comparacion_numero(Producto p1, Producto p2);
	bool comparacion_proveedor(Producto p1, Producto p2);

#endif
