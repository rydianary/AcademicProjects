#include<iostream>
#include<string.h>
struct libros{
	char titulo[50];
	char autor[50];
	char resumen[100];
	int libro_id; 
};

int main(){
	struct libros libro1; 
	strcpy(libro1.titulo, "C programming");
	strcpy(libro1.autor,"Nuha Ali"); 
	strcpy(libro1.resumen,"C programming resumen");
	libro1.libro_id=3545554; 
	std::cout<<"Titulo: "<<libro1.titulo<<"\n"; 
	std::cout<<"Autor: "<<libro1.autor<<"\n";
	std::cout<<"Resumen: "<<libro1.resumen<<"\n"; 
	
}
