/*Estructuras de datos - LIS 2032-1
Nombre Completo: Diana Laura Reyes Youshimatz
ID: 173391
Descripción breve del programa:
En el siguiente programa el usuario puede buscar distintons
elementos utilizando la busqueda secuencial o binaria. 
Para la busqueda binaria agregué un método de ordenamiento
para que funcionara correctamente 
y se anexan las siguientes características 
• Generar un arreglo de números aleatorios entre 0 y N.
• Un menú para elegir el método de búsqueda a realizar.
• Pedir al usuario el dato (número) a buscar.
• Se debe imprimir el arreglo generado.
• Se debe imprimir resultados: Método de búsqueda y si fue exitosa la búsqueda devolviendo la
ubicación del dato, de lo contrario indicar que no se encontró el dato buscado.
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubble_sort(int arr[],int n){
  int i,j,temp;
  for(i=0;i<n;i++){
      for(j=0;j<n-i-1;j++){
          if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
}
int bsec(int arr[], int n, int x) {
  for (int i=0; i<n; i++)
    if (arr[i]==x)
      return i;
  return -1;
}
int bbin(int arr[], int l, int r, int x) { 
    while (l<=r){ 
        int m=l+(r-l)/2; 
        if (arr[m]==x) 
            return m; 
        if (arr[m]<x) 
            l= m+1; 
        else
            r= m-1; 
    }  
    return -1; 
}   

int main() {
  printf("Size del arreglo: ");
  int n; scanf("%d",&n);
  int x = 1; int i, choice; 
  printf("\nArreglo: ");
  int arr[n];
  srand(time(NULL));
	for (i = 0; i<n; i++) {	
	    arr[i] = rand()%100;
	printf(" %d ", arr[i]);
  }
  printf("\n	1.Busqueda secuencial \n	2.Busqueda binaria \n	3. Salir ");
  while(1){
  	printf("\nElemento a buscar: "); scanf("%d",&x);
	printf("\nIngresa el numero de la opcion: "); scanf("%d",&choice);


    switch(choice){
    	case 1:	
  			(bsec(arr, n, x)== -1) ? printf("Error. Not found") : printf("Se encuentra en posicion: %d",bsec(arr, n, x)); 
  			break;
		case 2:  
			bubble_sort(arr,n);
			  printf("\nArreglo ordenado: ");
				for (i = 0; i<n; i++) {	
				printf(" %d ", arr[i]);
			  }
			printf("\n");
			(bbin(arr,0,n-1,x) == -1) ? printf("Error. Not found") : printf("Se encuentra en posicion: %d", bbin(arr,0,n-1,x));
			break; 
		case 3: 
			exit(0);	
	} 	
  }


}
