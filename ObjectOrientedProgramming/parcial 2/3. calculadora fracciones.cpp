#include<iostream>
#include<cmath>
using namespace std;

class Fraccion{
	
	double numer; 
	double denom;
	double fnume, fdeno;
	
	public: 
		Fraccion(){
		}
		Fraccion(double n, double d){
			this->numer=n;
			this->denom=d;
		}
		void setnume(double n){
			this->numer= n;
		}
		void setdeno(double d){
			this->denom=d;
		}
		double getnume(void){
			return this->numer; 
		}
		double getdeno(void){
			return this->denom;
		}
		Fraccion operator + (const Fraccion &afo){ 
		
			if(denom==afo.denom){
				fdeno=this->denom;
				fnume= this->numer + afo.numer;
			}

			else if(numer==0){
				fdeno=afo.denom;
				fnume=afo.numer;
			}
			else if(afo.numer==0){
				fdeno=this->denom;
				fnume=this->numer;
			}
			else{
				fdeno=this->denom*afo.denom;
				fnume=this->numer*afo.denom+afo.numer*denom;
			}	
			return Fraccion(fnume, fdeno);
		}
		void mostrarFraccion(){
			if(numer==0&& denom==0){
				cout<<" 0";
			}
			else if((numer!=0 ^ denom!=0) ||denom==0){
				cout<<numer;
			}
			else{
			cout<<this->getnume()<<"/"<<this->getdeno()<<'\n';
		}
		}
		Fraccion operator - (const Fraccion &afo){ 
		
			if(denom==afo.denom){
				fdeno=this->denom;
				fnume= this->numer - afo.numer;
			}

			else if(numer==0){
				fdeno=afo.denom;
				fnume=afo.numer;
			}
			else if(afo.numer==0){
				fdeno=this->denom;
				fnume=this->numer;
			}
			else{
				fdeno=this->denom*afo.denom;
				fnume=this->numer*afo.denom-afo.numer*denom;
			}	
			return Fraccion(fnume, fdeno);
		}
		Fraccion operator * (const Fraccion &afo){
			fnume=this->numer*afo.numer;
			fdeno=this->denom*afo.denom;
			return Fraccion(fnume, fdeno); 
		}
		Fraccion operator / (const Fraccion &afo){
			fnume=this->numer*afo.denom;
			fdeno=this->denom*afo.numer; 
			return Fraccion(fnume, fdeno);
		}
		Fraccion operator ==(const Fraccion &afo){
			fnume=this->numer==afo.denom;
			fdeno=this->denom==afo.numer; 
			return Fraccion(fnume, fdeno);

		}
				
};

int main(){
	int n; char choice; 
	Fraccion f1,f2(0,2), f4(2,3), f3;
	f1.setnume(2); f1.setdeno(5);
	
	f3=f1+f2;
	cout<<"\nCalculadora de fracciones";
	cout<<"\nFraccion 1: ";
	f1.mostrarFraccion();
	cout<<"\nFraccion 2: ";
	f2.mostrarFraccion();
	cout<<"\nFraccion 3: ";
	f4.mostrarFraccion();
	cout<<"\nOperacion: f2*f2+f1";
	cout<<"\nResultado: ";
	f3.mostrarFraccion();
	cout<<"\nOperacion: f4/f2";
	f3=f4/f2; cout<<"\nResultado: ";
	f3.mostrarFraccion();
	
	


}
