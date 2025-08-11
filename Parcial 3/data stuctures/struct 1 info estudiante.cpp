#include<stdio.h>
#include<iostream>
using namespace std;

struct informacionEstudiante{
	char *nombre;
	int id; 
	int edad; 
};

int main(){
	struct informacionEstudiante estudiante;
	estudiante.nombre="Steve";
	estudiante.id=1234; 
	estudiante.edad=30; 
	cout<<"Nombre estudiante: "<<estudiante.nombre<<"\n";
	cout<<"ID: "<<estudiante.id<<'\n';
	cout<<"Edad: "<<estudiante.edad<<'\n';
	
}
