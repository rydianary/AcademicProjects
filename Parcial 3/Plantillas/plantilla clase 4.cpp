#include<iostream>
using namespace std; 

template<class T, int tam>
class A{
	public:
		//atributo de clase 
		T arreglo[tam];
		//metodos de la clase
		void insertar(){
			int i =1;
			for(int j=0; j<tam; j++){
				arreglo[j]=i;
				i++;
			}
		}
		void mostrar(){
			for(int i=0; i<tam; i++){
				cout<<arreglo[i]<<" ";
			}
		}
};

int main(){
	A<int, 10> objeto;
	objeto.insertar();
	objeto.mostrar();
	return 0; 
	
}
