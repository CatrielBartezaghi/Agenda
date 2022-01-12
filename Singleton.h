#ifndef SINGLETON_H
#define SINGLETON_H
#include "Producto.h"
#include "Proveedor.h"
#include "Principal.h"
#include <string>
#include "Singleton.h"
/**
* @brief Esta clase se encarga de que exista una y solo una instancia de Agenda
*
* Esta clase no necesita ser instanciada, sino que solo se debe utilizar el 
* método estático ObtenerInstancia(), que devuelve la instancia, creandola
* si es la primera vez que se lo invoca.
**/
class Singleton:public Principal{
private:
	static Singleton *instancia; ///< puntero a la unica instancia, inicializado en NULL en el cpp
	Singleton():Principal(){}; ///< constructor privado, para que nadie pueda construir una instancia si no es mediante ObtenerInstancia()
//	Singleton(string _nombre, float _precio, string _categoria, int _stock, ubicacion _b, Proveedor provee):Principal(_nombre, _precio, _categoria, _stock, _b, provee){};
//	Singleton (string _nombre, float _precio, string _categoria, int _stock, string _letra, int _num, Proveedor provee):Principal(_nombre, _precio, _categoria, _stock, _letra, _num, provee){};
public:
	/**
	* @brief Método para crear/obtener la única instancia de la clase
	*
	* Si no hay una instancia creada (solo la primera vez que se invoca) crea una.
	* Si ya había una instancia creada, retorna esa instancia.
	**/
	static Singleton *ObtenerInstancia() {
		if (!instancia) instancia=new Singleton();
		return instancia;
	}
//	static Singleton *ObtenerInstancia(string _nombre, float _precio, string _categoria, int _stock, ubicacion _b, Proveedor provee){
//		if (!instancia) instancia=new Singleton(_nombre, _precio, _categoria, _stock, _b, provee);
//		return instancia;
//	}
};

#endif
