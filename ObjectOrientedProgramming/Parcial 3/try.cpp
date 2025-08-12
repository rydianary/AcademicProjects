#include<iostream>
#include<cmath>
#include<ctime>
#include<stdlib.h>
using namespace std; 

class CuentaBancaria {
	protected:
		int numCuenta[8];int n=6;
		int id[6]; 
	public: 
		CuentaBancaria(){
			generaid();
			
			
		}
		int generaid(){
//		srand(time(0));
		for(int i=0;i<n;i++){
			id[i]=rand()%10;
			}	
			
		}
		int generaracno(){
			srand(time(0));
			for(int i=0;i<n;i++){
				numCuenta[i]=rand()%10;
				}	
		}
		void mostrarInformacion(){
			cout<<"\nNumero de cuenta: ";
			for(int i=0;i<8;i++)
				cout<<numCuenta[i];
			cout<<"\nNumero de cliente: ";
			for(int i=0;i<6;i++)
				cout<<id[i];
			//cout<<"\nSaldo: "; this->consultarSaldo();
		//	cout<<"\nInteres: "<<this->interes;
				
				
		}

};

int main(){
	CuentaBancaria Hilton;

	Hilton.mostrarInformacion();
	
}
