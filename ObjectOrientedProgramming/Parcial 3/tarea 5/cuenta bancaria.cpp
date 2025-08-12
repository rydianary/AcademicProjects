#include<iostream>
#include<cmath>
#include<ctime>
#include<stdlib.h>
using namespace std; 

template <typename T>
class transacciones{
	protected:		
		long dinero=0; long cobro;
		T saldo=0;
		double interes=0.02;
		int Interes1(void){
			this->cobro=this->saldo*interes*365;
			return this->cobro;
		}
	public:
		
		void ingresar(float dinero){
			saldo+=dinero; 	}
		void retirar(float dinero){
			if (saldo>0)
				saldo-=dinero; 
			else
				cout<<"Fondos insuficientes";	
		}
		T consultarSaldo(){ 
			this->saldo-this->cobro;
			return this->saldo; }
		
};

template <typename T>
class CuentaBancaria: public transacciones<T>{
	protected:
		int numcuenta[8]; int n1=8;
		int id[6];  int n2=6;
	public: 
		CuentaBancaria(){
			generarid();
			this->saldo=100;
			this->interes; 	
		}
		int generarid(){
			srand(time(0));
			for(int i=0;i<8;i++){
				id[i]=rand()%10;
				}	
		}
		int generaracno(){
			srand(time(0));
			for(int i=0;i<sizeof(numcuenta);i++){
				numcuenta[i]=rand()%10;
				}	
		}
		void mostrarInformacion(){
			cout<<"\nNumero de cuenta: ";
			for(int i=0;i<8;i++){
				cout<<numcuenta[i];
			}
			cout<<"\nNumero de cliente: ";
			for(int i=0;i<6;i++)
				cout<<id[i];
			cout<<"\nSaldo: "; cout<<this->consultarSaldo();
			cout<<"\nInteres: "<<this->interes;
				
				
		}

};

int main(){
	CuentaBancaria<long> Hilton;
	Hilton.ingresar(26565452.25);
	Hilton.retirar(1010.15);
	Hilton.mostrarInformacion();
	
}
