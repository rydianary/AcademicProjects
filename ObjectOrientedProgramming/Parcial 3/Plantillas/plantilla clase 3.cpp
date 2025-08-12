#include<iostream>
using namespace std; 
//creacion de la plantilla 

template<class T>
class prueba{
	//atributos de la clase
	private: T arreglo[2];
	public: 
		prueba(T uno, T dos){
			arreglo[0]=uno;
			arreglo[1]=dos; 
		}
		void mostrar(){
			cout<<"valor de [0] es: "<<arreglo[0]<<"\n";
			cout<<"valor de [1] es: "<<arreglo[1]<<"\n";
		}
};

int main(){
	prueba<int> objeto(4,5);
	objeto.mostrar();
	prueba<string> objeto2("a","b");
	objeto2.mostrar();
	return 0;
}
