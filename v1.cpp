#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void convertir(string &x,int y)
{
	stringstream ss;
	ss << y;
	x = ss.str();	
}



class Plato{
	public:
		string name;
		string val;
		string ID;
		string stock;
		Plato(string x,string y,string z,string u){
			name = x;
			ID = y;
			val = z;
			stock = u;
		}
		
		print(){
			cout<<name<<endl;
			cout<<val<<endl;
			cout<<ID<<endl;
			cout<<stock<<endl;
		}	
};

class Carta{
	public:
	vector<Plato> lista_platos;
	
	Carta(){
		inicializar();
	}
	void infomenu(){
		inicializar();
		cout << "Platos : " << lista_platos.size() <<endl<< endl;
		for (int i = 0; i < lista_platos.size(); ++i) {
			cout << lista_platos[i].ID << ".";
			cout << lista_platos[i].name << ".........";
			cout << lista_platos[i].val<<"       Stock : ";
			cout << lista_platos[i].stock;
			cout<<endl<<endl;
		}
	}
	
	int actualizar(){
		std::ofstream ofs;
		ofs.open("platos.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
		
		ofstream myfile; 
		myfile.open("platos.txt",ios::app);
		if (myfile.is_open()){
			for(int i=0;i<lista_platos.size();i++){
				myfile <<lista_platos[i].name<<" "<<lista_platos[i].val<<" "<<lista_platos[i].ID<<" "<<lista_platos[i].stock<<endl;
  			}
  			myfile.close();
		}
  		else{
  				cout<<"Archivo no encontrado";	
		}
		
		return 1;
	}
	
	void inicializar(){
		lista_platos.clear();
		vector<string> V2;
		fstream myfile;
		myfile.open("platos.txt",ios::in);
		string line;
		if(myfile.fail()){
			cout<<"\nDatos no encontrados";
			exit(1);	
		}
			
		while(!myfile.eof()){
			getline(myfile,line);
		
			string temp;
			for(int i=0;i<line.size();i++){
				if( (int)line[i] != 32 ){
					temp.push_back(line[i]);
				}
				else{
					V2.push_back(temp);
					temp.clear();
				}
			}
			V2.push_back(temp);
			
			Plato aux(V2[0],V2[1],V2[2],V2[3]);
			lista_platos.push_back(aux);
			
			V2.clear();	
		}
		lista_platos.pop_back();
	}
	
	void Mostrar(){	
		vector<vector<string>> V1;
		vector<string> V2;
		ifstream myfile;
		myfile.open("platos.txt",ios::in);
		string line;
		if(myfile.fail()){
			cout<<"\nDatos no encontrados";
			exit(1);	
		}
			
		while(!myfile.eof()){
			getline(myfile,line);
			string temp;
			for(int i=0;i<line.size();i++){
				if( (int)line[i] != 32 ){
					temp.push_back(line[i]);
				}
				else{
					V2.push_back(temp);
					temp.clear();
				}
			}
			V2.push_back(temp);
			V1.push_back(V2);
			V2.clear();	
		}
		
		for(int i=0;i<V1.size()-1;i++){
			cout<<i+1<<". ";
			for(int j=0;j<V1[i].size();j++){
				cout<<V1[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};



class Chef{	
	public:
		
		void agregar(Carta &A){
			char rpt;	
			A.inicializar();
			do{			
				string nam;int val;string id;int st;
				cout<<"\nIngrese el nombre del plato : ";cin>>nam;
			
				do{
					cout<<"\nIngrese el precio : ";cin>>val;					
				}while(val<=0);
				
				string valor;
				convertir(valor,val);
				
				cout<<"\nIngrese el ID : ";cin>>id;
				
				do{
				cout<<"\nIngrese el stock : ";cin>>st;
				}while(st<=0);	
				
				string stock;
				convertir(stock,st);
				
				Plato p(nam,id,valor,stock);
				A.lista_platos.push_back(p);
									
			
				cout<<"Desea ingresar otro plato ? S/N : ";cin>>rpt;
				
  			}while( rpt == 'S' || rpt == 's');
  			A.actualizar();
		}
		
		int modificarplato(Carta &A) {
			string key;
			A.inicializar();
			cout<<"Nombre de plato a modificar ";cin>>key;
			for (int i = 0; i < A.lista_platos.size(); ++i) {
				if (A.lista_platos[i].name == key) {
					int opcion = 1;
					while (opcion != 0) {
						cout << "Modificar : " << endl;
						cout << "1. Nombre" << endl;
						cout << "2. Precio" << endl;
						cout << "3. Stock" << endl;
						cout << "0. Guardar cambios" << endl;
						cin >> opcion;
						switch (opcion)
						{
						case 1:
							cout << "Actual -> " << A.lista_platos[i].name << endl;
							cout << "Nuevo  <- "; cin >> A.lista_platos[i].name;
							break;
						case 2:
							cout << "Actual -> " << A.lista_platos[i].val << endl;
							cout << "Nuevo  <- "; cin >> A.lista_platos[i].val;
							break;
						case 3:
							cout << "Actual -> " << A.lista_platos[i].stock << endl;
							cout << "Nuevo  <- "; cin >> A.lista_platos[i].stock;
							break;
						default:
							break;
						}
						
					}
					A.actualizar();
					return 1;
				}
			}
		cout << "Plato no encontrado" << endl;
		return 0;
	}
};

int main(){
	Chef C;
	Carta menu;
	
	int sd=-1;
	while(sd!= 0){
		cout<<"1. Agregar Plato"<<endl;
		cout<<"2. Modificar Plato"<<endl;
		cout<<"3. Eliminar Plato"<<endl;
		cout<<"4. Ver carta"<<endl;
		cout<<"0. Salir"<<endl;
		cin>>sd;
		switch(sd){
			case 1:
				C.agregar(menu);
				break; 
			case 2:
				C.modificarplato(menu);
				break;
			case 3:
				break; 
			case 4:
				menu.infomenu();
				break;
			case 0:
				break; 
			default:
				break;
		}
	}
	
	
	
//	Menu<string,int> p2;
//	p2.Mostrar();
	
	
	return 0;
}
