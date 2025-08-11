//USO BASICO DE UNA CLASE 
#include <iostream>
using namespace std; 

class fecha{
	private: 
	int y, d, m;
	public: 
	//primer metodo
	void obtenerFecha(void){
		printf("A%co:", 164);
		cin>>y;
		cout<<"Mes: ";
		cin>>m;
		cout<<"Dia: ";
		cin>>d;
	}
	// segundo metodo
	void mostrarFecha(void){
		cout<<"La fecha es: ";
		cout<<d<<"/"<<m<<'/'<<y;
	}
};

//función principal 
int main(){
	//creación de objetos
	fecha fecha1;
	fecha1.obtenerFecha();
	fecha1.mostrarFecha();}
