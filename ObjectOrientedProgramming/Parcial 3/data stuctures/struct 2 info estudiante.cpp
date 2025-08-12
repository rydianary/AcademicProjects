#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std; 
struct estudiante{
	int id;
	char nombre[30]; 
	float porcentaje;
};
int main(){
	int i; 
	struct estudiante record[2];
	record[0].id=1;
	strcpy(record[0].nombre,"Raul");
	record[1].id=2;
	strcpy(record[1].nombre,"Susana");
	record[1].porcentaje=90.5;
	record[2].id=3; 
	strcpy(record[2].nombre, "Tomas"); 
	record[2].porcentaje=81.5;
	for(i=0; i<3; i++){
		cout<<"Record de estudiante: "<<i+1<<"\n";
		cout<<"Id: "<< record[i].id<<"\n";
		cout<<"Nombre: "<<record[i].nombre<<"\n";
		cout<<"Porcentaje: "<<record[i].porcentaje<<"\n";
	}
}
