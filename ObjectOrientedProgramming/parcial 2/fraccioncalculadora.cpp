#include<iostream>
#include<cmath>
using namespace std;

class Fraccion{
	double numer; 
	double denom;
	double fnume, fdeno;
	
	public: 
		Fraccion(){
			numer = 1.0; 
			denom = 1.0; 
		}
		Fraccion(double n, double d){
			numer=n;
			denom=d;
		}
		Fraccion operator + (const Fraccion &afo){ 
			fnume= numer + afo.numer;
			fdeno= denom + afo.denom;
			return Fraccion(fnume, fdeno);
		}
		void mostrarFraccion(){
			cout<<numer<<"/"<<denom<<'\n';
		}
		Fraccion operator - (const Fraccion &afo){
			fnume= numer - afo.numer; 
			fdeno=denom+ afo.denom; 
			return Fraccion(fnume, fdeno);
		}
		Fraccion operator * (const Fraccion &afo){
			fnume=numer*afo.numer;
			fdeno=denom*afo.denom;
			return Fraccion(fnume, fdeno); 
		}
		Fraccion operator / (const Fraccion &afo){
			fnume=numer*afo.denom;
			fdeno=denom*afo.numer; 
			return Fraccion(fnume, fdeno);
		}
		
			
	
};

int main(){
	int n; char choice; 
	Fraccion f1(2,5),f2(5,5), f3;
	do{
	
		cout<<"***CALCULADORA DE FRACCIONES:***\n";
		cout<<"\nFraccion 1: "; f1.mostrarFraccion();
		cout<<"\nFraccion 2: "; f2.mostrarFraccion();
		cout<<"\nElige la operacion que desees realizar";
		cout<<"\n 1. Suma\n 2. Resta\n 3.Multiplicacion\n 4. Division\n "; 
		int answ; cin>>answ; 
		switch(answ){
			case 1: {
				cout<<"Resultado (suma): ";
				f3=f1+f2;
				f3.mostrarFraccion();
				break;
			}
			case 2:{
				cout<<"Resultado (diferencia): "; 
				f3=f1-f2;
				f3.mostrarFraccion();
				break;
			}
			case 3: {
				cout<<"Resultado (producto): "; 
				f3=f1*f2;
				f3.mostrarFraccion();
				break;
			}
			case 4:{
				cout<<"Resultado (cociente): ";
				f3=f1/f2;
				f3.mostrarFraccion();
				break;
			}
			default: {
				cout<<"Opcion no valida";
				break;
			}
		}
		cout<<"\n Presione 'y' para continuar, 'n' para finalizar\n"; 
		cin>>choice;
	}	
	while (choice == 'y');


}
