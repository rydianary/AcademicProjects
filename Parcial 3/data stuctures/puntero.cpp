#include<iostream>
using namespace std; 
int main(){
	int a=0;  //declaracion de la variable de tipo entero
	int *puntero; //declaracion de la variable puntero tipo entero
	puntero=&a; //asignacion de la direccion memoria de a 
	cout<<"Valor de puntero: "<<*puntero<<'\n';
	cout<<"Valor de direccion de memoria de puntero: "<<puntero<<'\n';
}


