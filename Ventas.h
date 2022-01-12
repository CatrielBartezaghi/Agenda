#ifndef VENTAS_H
#define VENTAS_H
#include "Producto.h"
#include <string>
#include <wx/string.h>
using namespace std;
struct reg_venta{
	char producto[256];
	int dia, mes, anio;
	char nombre[256];
	char telefono[256];
	char DNI[256];
	char otro_dato[256];
	float precio_venta;
	int cantidad;
};


class Venta{
	string producto;
	int dia, mes, anio;
	string nombre;
	string telefono;
	string DNI;
	string otro_dato;
	float precio_venta;
	int cantidad;
public:
	Venta();
	Venta(Producto pro,int d, int m, int a, string nom, string tel, string dn, string otro, int can);
	string verpro();
	int verdia();
	int vermes();
	int veranio();
	string vernom();
	string vertel();
	string verdni();
	string verotro();
	wxString verpre_venwx();
	float verpre_ven();
	int vercantidad();
	
	void modpro(Producto pro);
	void moddia(int d);
	void modmes(int m);
	void modanio(int a);
	void modnom (string nom);
	void modtel(string tel);
	void moddni(string dn);
	void modotro(string otro);
	void modpre(float pre);
	void modcan(int can);
	
	void GuardarVen(ofstream &archi);
	
	void LeerVen(ifstream &archi);
	
	string ValidarDatosVenta(int a, int stock, int cantidad);
};
	bool comparacion_producto_venta(Venta v1, Venta v2);
	bool comparacion_nombre_venta(Venta v1,Venta v2);
	bool comparacion_fecha_venta(Venta v1, Venta v2);
	bool comparacion_telefono_venta(Venta v1, Venta v2);
	bool comparacion_dni_venta(Venta v1, Venta v2);
	bool comparacion_otro_dato_venta(Venta v1, Venta v2);
	bool comparacion_precio_venta(Venta v1, Venta v2);
#endif
