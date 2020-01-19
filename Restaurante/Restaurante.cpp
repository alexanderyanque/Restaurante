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
	map<string, vector<plato*>*> platos; //noimbre seccion, platos
	int crearseccion(string nombre) {
		if (platos.find(nombre) != platos.end()) {
		//	cout << "existe" << endl;
			return -1;
		}
		vector<plato*>* nseccion;//nueva seccion
		nseccion = new vector<plato*>;
		platos.insert(pair<string, vector<plato*>*>(nombre, nseccion));
		return 1;
	}
	//crear	//modificar //eliminar
	void infomenu() {
		cout <<"secciones : "<< platos.size()<<endl;
		for (map<string, vector<plato*>*>::iterator i = platos.begin(); i != platos.end(); i++) {
			vector<plato*>* lista_platos;
			lista_platos = i->second;
			string nombre = i->first;
			cout << nombre << " ";
			cout << lista_platos->size() << endl;
			/*for (int j = 0; j < lista_platos->size(); ++j) {
				cout << (lista_platos);
			}*/
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
