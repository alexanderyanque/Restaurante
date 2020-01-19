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

int insplatoBD(plato a);//se inserta el plato en la BD

class carta {
public:
	string fecha;
	//	vector<plato *> platos;
	vector<plato > lista_platos;

	int crearplato(string nombre, string desc, unsigned int precio) {
		//		plato nuevo;
		plato nuevo(precio, nombre, desc);
		lista_platos.push_back(nuevo);
		if (insplatoBD(nuevo) == 1) {
			return 1;
		}
		return -1;//error
	}

	int modificarplato(string key) {
		for (int i = 0; i < lista_platos.size(); ++i) {
			if (lista_platos[i].nombre == key) {
				int opcion;
				while (opcion != 0) {
					cout << "Opcion a modificar : " << endl;
					cout << "1. Nombre" << endl;
					cout << "2. Precio" << endl;
					cout << "3. Descripcion" << endl;
					cin >> opcion;
					
				}
				return 1;
			}
		}
		cout << "Plato no encontrado" << endl;
		return 0;
	}

	int cargarcarta();//se carga desde el .txt

	
	

	void infomenu(){
		cout << "Platos : " << lista_platos.size() << endl;
		for (int i = 0; i < lista_platos.size(); ++i) {
			cout << lista_platos[i].nombre << " : ";
			cout << lista_platos[i].precio;
			cout << endl;
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
	
	menu.infomenu();
	return 0;
}
