// Restaurante.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

#define salto cout<<endl<<endl;
	
using namespace std;

class usuario {
public:
	string nombre;
	string DNI;
	string pw;
	int tipo;
	int id;
	usuario(string a, string b, string c, int t) {
		DNI = b;
		pw = c;
		tipo = t;
		nombre = a;
		id = 1;
	}
};

class plato {
public:
	int id = 0;
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

int insplatoBD(plato a)
{
	return 1;
	//se inserta el plato en la BD
}
class carta {
public:
	string fecha;
	//	vector<plato *> platos;
	vector<plato > lista_platos;

	int crearplato(string nombre, string desc, unsigned int precio) {
		//		plato nuevo;
		plato nuevo(precio, nombre, desc);
		lista_platos.push_back(nuevo);
		if (guardarcarta() == 1) {
			return 1;
		}
		return -1;//error
	}

	int modificarplato(string key) {
		for (int i = 0; i < lista_platos.size(); ++i) {
			if (lista_platos[i].nombre == key) {
				int opcion = 1;
				while (opcion != 0) {
					cout << "Modificar : " << endl;
					cout << "1. Nombre" << endl;
					cout << "2. Precio" << endl;
					cout << "3. Descripcion" << endl;
					cout << "0. Salir" << endl;
					cin >> opcion;
					switch (opcion)
					{
					case 1:
						cout << "Actual -> " << lista_platos[i].nombre << endl;
						cout << "Nuevo  <- "; cin >> lista_platos[i].nombre;
						break;
					case 2:
						cout << "Actual -> " << lista_platos[i].precio << endl;
						cout << "Nuevo  <- "; cin >> lista_platos[i].precio;
						break;
					case 3:
						cout << "Actual -> " << lista_platos[i].descripcion << endl;
						cout << "Nuevo  <- "; cin >> lista_platos[i].descripcion;
						break;
					default:
						break;
					}
					salto;
				}
				return 1;
			}
			guardarcarta();
		}
		cout << "Plato no encontrado" << endl;
		return 0;
	}

	int cargarcarta() { return 1; }//se carga desde el .txt


	int guardarcarta() { return 1; }//se borra el .txt y se reemplaza por el nuevo
	

	void infomenu(){
		cout << "Platos : " << lista_platos.size() << endl;
		for (int i = 0; i < lista_platos.size(); ++i) {
			cout << lista_platos[i].nombre << ".......";
			cout << lista_platos[i].precio;
			cout << endl;
			cout << lista_platos[i].descripcion;
			salto;
		}
	}
};

class pedido {
public:
	int id_mozo;
	vector<plato*> platos;
	int total;
	string comentario;

};

class comanda {
public:

};


int login(usuario* res, string id, string password);


int main()
{
	carta menu;
	menu.cargarcarta();
	menu.crearplato("Mazamorra", "Mazamorra de Pinha, con frutas", 32);
	menu.infomenu();
	menu.modificarplato("Mazamorra");
	//menu.modificarplato("s");
	menu.infomenu();
	return 0;
}
