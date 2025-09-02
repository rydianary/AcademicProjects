/*Estructuras de datos - LIS 2032-1
Nombre Completo: Diana Laura Reyes Youshimatz
ID: 173391
Descripción breve del programa:
Se implementa de double hashing para una tabla de tama{o 6 y posteriormente
de tamaño 6 y se agregan las siguientes características 
Inserte los datos: 4, 17, 30, 55, 90, 11, 56 y 77.
• Tome h1 = k mod 9 y h2 = k mod 6.
• Debe tener un menú de: Insertar datos, búsqueda de datos y eliminar datos
este metodo me costo un poco de implementar y vi varios videos de personas de la india para entender mejor jejej :c 
}*/ 
#include <stdio.h>
#include <stdlib.h>  
#define TABLE_SIZE 9 
#define Prim 6 
class Hashdoble 
{ 
    int *tabla; 
    int tam; 
public: 
    bool full(){ 
        return (tam == TABLE_SIZE); 
    } 
    int hash1(int key){ 
        return (key%TABLE_SIZE); 
    } 
    int hash2(int key){ 
        return (Prim-(key%Prim)); 
    } 
    Hashdoble(){ 
        tabla = new int[TABLE_SIZE]; 
        tam = 0; 
        for (int i=0; i<TABLE_SIZE; i++) 
            tabla[i] =-1; 
    } 
    void insert(int key) { 
        if (full()) 
            return; 
        int i=hash1(key);
		 
        if (tabla[i]!=-1) { 
            int i2=hash2(key); 
            int i=1; 
            while (1){ 
                int newi=(i+i*i2)%TABLE_SIZE; 
                if (tabla[newi] == -1){ 
                    tabla[newi] = key; 
                    break; 
                } 
                i++; 
            } 
        } 
        else
            tabla[i] = key; 
        tam++; 
    } 
    void print(){ 
        for (int i = 0; i < TABLE_SIZE; i++){ 
            if (tabla[i] != -1) 
                printf(" %d --->%d\n",i,tabla[i]);             
           else
           	printf(" %d \n",i);
                
        } 
    } 
}; 

int main() 
{ 
    int a[] = {4, 17, 30, 55, 90, 11, 56, 77}; 
    int n = sizeof(a)/sizeof(a[0]); 
    Hashdoble h; 
    for (int i = 0; i < n; i++) 
        h.insert(a[i]); 
  
    // display the hash Table 
    h.print(); 
    return 0; 
} 
