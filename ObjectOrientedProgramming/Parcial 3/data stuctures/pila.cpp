#include"interfaz.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std; 

template<typename X>
class pila: public estructuraDatos<X>, public nodo<X>{
	private:
		nodo<X> *raiz;
	public:
		//inicilizar pimer elemento de la estructura
		pila(){ raiz = NULL;}
		~pila(void){ //eliminar todo
			nodo<X> *elemento=raiz;
			nodo<X> *temporal;
			while(elemento !=NULL){
				temporal=elemento;
				elemento=elemento->siguiente;
				delete temporal;
			}
		}
		//insertar elemento en pila(setter) push
		void insertar(X dato){
			//puntero a nodo
			nodo<X> *elemento;
			//creacion de nodo
			elemento=new nodo<X> ();
			//guardar info en la pila
			elemento->dato = dato;
			if(raiz==NULL){
				raiz = elemento;
				elemento->siguiente;
			}
			else{
				//punto apunto al nuevo nodo
				elemento->siguiente=raiz;
				raiz=elemento;
			}
		}//pop
		X extraer(void){
			if(raiz!=NULL){
				//si la pila no esta vacia guardamos la info del 1er nodo
				X informacion = raiz->dato;
				//puntero auxiliar
				nodo<X> *elemento=raiz;
				raiz=raiz->siguiente;
				delete elemento;
				return informacion;
			}
			else{ return -1;}
		}
		void imprimir(void){
			nodo<X> *elemento=raiz;
			cout<<"Listado de todos los elementos de la pila\n";
			while(elemento !=NULL){
				//imprimir c/u elementos
				cout<<"elemento: "<<elemento->dato<<"\n";
				elemento = elemento->siguiente;
			}
	}
};
int main(void){
	pila<int> pila1;
	pila1.insertar(10);
	pila1.insertar(40);
	pila1.insertar(3);
				
	pila<float> pila2;
	pila2.insertar(20.34);
	pila2.insertar(50.12);
	pila2.insertar(4.11);
	cout<<"Pila 1: \n"; pila1.imprimir();
	cout<<"Pila 2: \n"; pila2.imprimir();
	cout<<"\nExtraemos de la pila 1: "<<pila1.extraer()<<"\n";
	pila1.imprimir();
	cout<<"\nExtraemos de la pila 2: "<<pila2.extraer()<<"\n";
	pila2.imprimir();
	return 0;			
}
