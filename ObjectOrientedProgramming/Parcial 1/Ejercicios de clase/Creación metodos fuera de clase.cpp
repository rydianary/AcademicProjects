#include<iostream>
using namespace std; 
//creacion de la clase 
class ClaseA{
	public:
		void poner(int val);
		int obtener(void);
	private:
		int a; 
		
};
//declaraci�n de las funciones fuera de la clase
int ClaseA::obtener(void){
	return a;
	}
void ClaseA::poner(int val){
	a=val;
}

//funci�n principal
int main(){
	ClaseA a;
	a.poner(20);
	cout<<"El valor de a es: "<<a.obtener();
	return 0; 
	
}
