#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include <string>
#include <vector>
using namespace std;
struct reg_proov{
	char nombre[256];
	char telefono[256];
	char direccion[256];
	char email[256];
	char otro_contacto[256];
};

class Proveedor{
	string nombre;
	string telefono;
	string direccion;
	string email;
	string otro_contacto;
public:
	Proveedor();
	Proveedor(string nom, string tel, string dir, string em, string otro);
	string vernom();
	string vertel();
	string verdir();
	string verem();
	string verotr();
	
	void modnom(string nomb);
	void modtel(string tele);
	void moddir(string dire);
	void modem(string ema);
	void modotro(string otro);
	
	void GuardarProv(ofstream &archi);
	
	void LeerProv(ifstream &archi);
	
	
	
	string ValidarDatos();
};

bool comparacion_nombre_prov(Proveedor p1, Proveedor p2);
bool comparacion_telefono_prov(Proveedor p1, Proveedor p2);
bool comparacion_direccion_prov(Proveedor p1, Proveedor p2);
bool comparacion_email_prov(Proveedor p1, Proveedor p2);
bool comparacion_otro_contacto_prov(Proveedor p1, Proveedor p2);
#endif
