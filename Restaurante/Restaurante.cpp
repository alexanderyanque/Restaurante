// Restaurante.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
	
using namespace std;

class usuario {
public:
	string nombre;
	string id;
	string pw;
	int tipo;
	usuario(string a, string b, string c, int t) {
		id = b;
		pw = c;
		tipo = t;
		nombre = a;
	}
};

class plato {
public:
	string nombre;
	string descripcion;
	unsigned int precio;
	plato(int prec, string nomb, string desc) {
		nombre = nomb;
		precio = prec;
		descripcion = desc;
	}
	//crear	//modificar //eliminar
};

class carta {
public:
	string fecha;
	vector<plato *> platos;
	//crear	//modificar //eliminar
};

/*class pedido {
public:

};
*/

int login(usuario* res, string id, string password);


int main()
{
    std::cout << "Hello World!\n"; 
}
