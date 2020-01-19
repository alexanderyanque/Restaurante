// Restaurante.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
	
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
	//	vector<plato *> platos;
	vector<plato > lista_platos;
	int crearseccion(string nombre) {
		
		return 1;
	}

	int crearplato(string nombre, string desc, unsigned int precio ) {
//		plato nuevo;
	}

	

	void infomenu() {
		cout <<"platos : "<< lista_platos.size()<<endl;
		for (int i = 0; i < lista_platos.size(); ++i) {
			cout << lista_platos[i].nombre;
		}
	}
};

/*class pedido {
public:

};
*/

int login(usuario* res, string id, string password);


int main()
{
	carta menu;
	
	menu.crearseccion("entrada");
	menu.crearseccion("entrada");
	menu.crearseccion("postre");
	menu.infomenu();
	return 0;
}
