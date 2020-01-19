// Restaurante.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class usuario {
public:
	string nombre;
	string id;
	string pw;
	int tipo;
	usuario(string a, string b, string c, int t) {
		nombre = a;
		id = b;
		pw = c;
		tipo = t;
	}
};



int login(usuario* res, string id, string password);


int main()
{
    std::cout << "Hello World!\n"; 
}
