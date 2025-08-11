#include<iostream>
#include<cmath>
using namespace std; 
template<class T>
class complejo{
	//elementos privados
	private: 
		T real; 
		T ima; 
		T cr, ci;
	//elementos publicos; 
	public:
		void setComplejo(T a, T b){
			real=a;
			ima= b; 
		}
		T getParteReal(){
			return real;
		}
		T getParteIma(){
			return ima;
		}
		complejo(){
			real = 1.0;
			ima = 1.0 ;}
		complejo(T rx, T mx){
			this->real = rx; 
			this->ima = mx; }
		complejo operator +(const complejo &aco){ 
			cr= this->real + aco.real; 
			ci= this->ima+ aco.ima;
			return complejo(cr, ci); }
		complejo operator -(const complejo &aco){ 
			cr= this->real - aco.real; 
			ci= this->ima- aco.ima;
			return complejo(cr, ci); }
		complejo operator *(const complejo &aco){ 
			cr= ((this->real * aco.real)- (this->ima* aco.ima)); 
			ci= ((this->real*aco.ima)+this->ima*aco.real);
			return complejo(cr, ci); }
		complejo operator /(const complejo &aco){
			cr= ((this->real* aco.real ) + (this->ima*aco.ima))/(pow(aco.real,2)+pow(aco.ima,2));
			ci= (this->real*-1*aco.ima+this->ima*aco.real)/(pow(aco.real,2)+ pow(aco.ima,2));
			return complejo(cr, ci); 
		}
		complejo operator *(int k){
			cr= this->real*k; 
			ci= this->ima*k;
			return complejo(cr, ci); 
		}
		complejo operator !=(const complejo &aco){
		if(this->real != aco.real || this->ima != aco.ima){
			cout<<"Desigualdad consistente\n";}
			else{cout<<"Desigualdad inconsistente";
			}}
		complejo operator ==(const complejo &aco){
				if(this->real == aco.real && this->ima==aco.ima){
					cout<<"Igualdad consistente\n";}
				else{cout<<"Igualdad inconsistente\n";	}
		}
		complejo operator =(const complejo &aco){
			this->real=aco.real;
			this->ima=aco.ima;
			return complejo(real, ima);
		}
		void mostrarComplejo(void){
			cout<<"("<<this->getParteReal()<<", "<<this->getParteIma()<<"i)\n"; }
};

//función principal
int main(){
	complejo<double> c1,c2,c3;
	complejo<int> a1,a2,a3;
	a1.setComplejo(1,2);
	a2.setComplejo(2,5);
	c1.setComplejo(2.0,3.0);
	c2.setComplejo(1.0,4.0);
	cout<<"Complejo c1: "; c1.mostrarComplejo();	
	cout<<"Complejo c2: "; c2.mostrarComplejo();
	cout<<"Complejo a1: "; a1.mostrarComplejo();
	cout<<"Complejo a2: "; a2.mostrarComplejo();
	cout<<"\nSon iguales c1 y c2? "; c1==c2;
	cout<<"\na1+a2: "; a3=a1+a2;
	a3.mostrarComplejo(); 
	cout<<"a1-a2: "; a3=a1-a2;
	a3.mostrarComplejo(); 
	cout<<"c1*c2: "; c3=c1*c2;
	c3.mostrarComplejo();
	cout<<"c1/c2: "; c3=c1/c2;
	c3.mostrarComplejo();
	cout<<"\nAsignar c2 a c1: \n"; c1=c2;
	cout<<"Complejo c1: "; c1.mostrarComplejo();
					
}
