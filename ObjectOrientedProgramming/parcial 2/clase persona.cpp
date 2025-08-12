#include<iostream>
#include<cmath>
#include<ctime>
#include<stdlib.h>
using namespace std; 

class Persona{
	private:
		int id[5];
		int i,edad=0; 
		float peso=0.0, altura=0.0, imc;
		string sexo, nombre;
		
		int generaid(){
//		srand(time(0));
		for(i=0;i<5;i++){
			id[i]=rand()%10;
			}	
		}
		void imprimirid(){
			for(i=0; i<5;i++){
				cout<<id[i];
			}	
		}
		void respEdad(){
			if(esMayorDeEdad()==1){cout<<" -Persona mayor de edad. \n";}
			else{cout<<" -Persona menor de edad. \n";}  }
		
		void respPeso(){
			if(calcularIMC()==-1){
				cout<<" -Persona por debajo del peso ideal.\n";
			}
			else if(calcularIMC()==0){
				cout<<" -Persona en peso ideal.\n";
			}
			else{
				cout<<" -Persona con sobrepeso\n";
			}
		}	
	public:
		Persona(){
			generaid();
		}
		Persona(string a, string b, int d){
			sexo=a;
			nombre=b;
			edad= d;
			generaid(); 
		}
		Persona (string a, string b, /*int c[5],*/ int d, float e, float f ){
			sexo=a;
			nombre=b; 
			//id[5]=c[5];
			generaid(); 
			edad= d; 
			peso = e; 
			altura = f; 
			generaid();
		}  
		void setSexo(string a);
		void setNombre(string b);
		void setEdad(int d);
		void setPeso(float e);
		void setAltura(float f);
		int calcularIMC();
		int esMayorDeEdad();
		void informacionPersona();
		
};

void Persona::setSexo(string a){
if(a=="femenino" || a=="masculino"){
	sexo=a;}
else{
	sexo=="indefinido";}
}

void Persona::setNombre(string b){
nombre=b;}

void Persona::setEdad(int d){edad=d;}

void Persona::setPeso(float e){peso = e;}

void Persona::setAltura(float f){altura = f;}	


Persona::calcularIMC(){
	imc=peso/(pow(altura,2) ) ;
	if(imc>20){ return -1;}
	else if(imc>=20 && imc<=25){ return 0;}
	else {return 1;}		
}

Persona::esMayorDeEdad(){
	if(edad>=18){
		return 1;}
	else{
		return 0;}
}


void Persona::informacionPersona(){
	cout<<"\n\nINFORMACION PERSONAL\n";
	cout<<"ID: ";
	imprimirid(); 
	cout<<"\nNombre: "<<nombre<<'\n';
	cout<<"Edad: "<<edad<<'\n';
	respEdad();
	cout<<"Sexo: "<<sexo<<'\n';
	cout<<"Peso: "<<peso<<'\n';
	respPeso();
	cout<<"Altura: "<<altura<<'\n';
}

int main(){
	Persona obj1("femenino","Juanita Bananas",25, 88.1, 1.90);
	obj1.calcularIMC();
	obj1.esMayorDeEdad();
	obj1.informacionPersona();
	
	Persona obj2("masculino","Carlos Perez",14);
	obj2.calcularIMC();
	obj2.esMayorDeEdad();
	obj2.informacionPersona();
	
	Persona obj3; 
	obj3.setNombre("Ana Huang");
	obj3.setSexo("femenino");
	obj3.setEdad(12);
	obj3.setPeso(49.5);
	obj3.setAltura(1.60);
	obj3.informacionPersona();
}
