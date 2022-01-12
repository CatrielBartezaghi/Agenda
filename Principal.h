#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Producto.h"
#include "Proveedor.h"
#include <vector>
#include "Ventas.h"
using namespace std;

#define NO_SE_ENCUENTRA -1

enum CriterioOrden { ORDEN_NOMBRE, ORDEN_PRECIO, ORDEN_CATEGORIA, ORDEN_STOCK, ORDEN_LETRA, ORDEN_NUMERO, ORDEN_PROVEEDOR };

enum CriterioOrdenProveedor{ORDEN_NOMBRE_PROVEEDOR, ORDEN_TELEFONO_PROVEEDOR, ORDEN_DIRECCION_PROVEEDOR, ORDEN_EMAIL_PROVEEDOR, ORDEN_OTRO_PROVEEDOR};

enum CriterioOrdenVenta{ORDEN_PRODUCTO_VENTA, ORDEN_FECHA_VENTA, ORDEN_NOMBRE_VENTA, ORDEN_TELEFONO_VENTA, ORDEN_DNI_VENTA, ORDEN_PRECIO_VENTA, ORDEN_OTRO_DATO_VENTA}; 

class Principal{
	vector <Producto> V;
	vector <Proveedor> U;
	vector <Venta>W;
	string nombreArchivoProductos="Productos.dat";
	string nombreArchivoProveedores="Proveedores.dat";
	string nombreArchivoVentas="Ventas.dat";
public:
	
	Principal();
	bool GuardarProductos();
	bool GuardarProveedores();
	bool GuardarVentas();
	int cant_prod();
	int cant_prov();
	int cant_vent();
	/// @brief Devuelve un registro para ver o modificar
	Producto &operator[](int i);
	Proveedor &RetornarProveedor(int j);
	Venta &RetornarVenta(int i);
	/// @brief Devuelve un registro para ver o modificar
	Producto &VerProducto(int i);
	Proveedor &VerProveedor(int i);
	Venta &VerVenta(int i);
	void Ordenar(CriterioOrden criterio);
	void OrdenarProveedor(CriterioOrdenProveedor criterio);
	void OrdenarVenta(CriterioOrdenVenta criterio);
	void AgregarProducto(Producto &p);
	void AgregarProveedor(Proveedor &p);
	void AgregarVenta(Venta &v);
	void ReemplazarProveedor(Proveedor &p, int pos);
	void ReemplazarVenta(Venta &v, int pos);
	void EliminarProducto(int a);
	void EliminarProveedor(int i);
	void EliminarVenta(int i);
	int BuscarNombre(string parte, int pos_desde);
	int BuscarNombreProv(string parte, int pos_desde);
	int BuscarNombreVenta(string parte, int pos_desde, int criteriobusqueda);
};

#endif
