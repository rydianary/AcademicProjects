#include"interfaz.h"
#include<iostream>
#include<cstdlib>

using namespace std; 

template<typename X>
class pila: public estructuraDatos<X>, public nodo<X>{
	private:
		nodo<X> *raiz; int count=0;
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
			if(empty()==1){
				raiz = elemento;
				elemento->siguiente;
				count+=1;
			}
			else{
				//punto apunto al nuevo nodo
				elemento->siguiente=raiz;
				raiz=elemento;
				count+1;
			}
		}
		void insertarrand(){
			nodo<X> *elemento;
			elemento=new nodo<X> ();
			//guardar info en la pila
			elemento->dato = rand()%100;
			if(empty()==1){
				raiz = elemento;
				elemento->siguiente;
				count+=1;
			}
			else{
				//punto apunto al nuevo nodo
				elemento->siguiente=raiz;
				raiz=elemento;
				count+1;
			}
		}
		//pop
		X extraer(void){
			if(empty()!=1){
				//si la pila no esta vacia guardamos la info del 1er nodo
				X informacion = raiz->dato;
				//puntero auxiliar
				nodo<X> *elemento=raiz;
				raiz=raiz->siguiente;
				delete elemento;
				return informacion;
				count-=1;
			}
			else{ return -1;}
		}
		X extraer2(void){
			for(int i=0;i<2;i++){
				extraer();
		}
		}
		X stacksize(void){
			return count;
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
		int empty(void){
				if(raiz==NULL){
					return 1;
				}
				else{
					return 0;
				}	
		}
	
};
int main(void){
	pila<int> pila1;
	pila1.insertar(10);
	pila1.insertar(40);
	pila1.insertar(3);

			
	cout<<"\nPila 1: \n"; pila1.imprimir();

	pila1.extraer2();
	pila1.imprimir();
	cout<<"Pila size: "<<pila1.stacksize();


	return 0;			
}
