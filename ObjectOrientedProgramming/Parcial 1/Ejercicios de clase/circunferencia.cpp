#include<iostream>
using namespace std; 
//clase
class circulo{
	double radio; 
	public: 
	circulo(double r){
		radio = r; 
	}
	double circunferencia(){
		return 2*radio*3.1416;
	}
};

int main(){
	//creacion de objetos
	circulo objeto1(10.0);
	circulo objeto2=20.0; 
	//uso de objetos
	cout<<"circunferencia: "<<objeto1.circunferencia()<<'\n';
	return 0; 
	
}
