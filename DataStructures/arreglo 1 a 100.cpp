#include <stdio.h>

int main()

{

   int x, tabla[100];

   printf("\n Programa que obtiene los 100 primeros números enteros ");

   printf("\n y los almacena en un arreglo, también los imprime en pantalla \n\n ");

   // Asignación de datos al arreglo

   for (x=0;x<100;x++) //x++ es un incremento en 1, es decir; x= x+1;

   {

       tabla[x]=x;

   }



   //Impresión del arreglo

   for (x=0;x<100;x++)

   {

       printf("%d, ",tabla[x]); // Poner \n si se quiere imprimir en forma vertical

   }

   printf("\n El valor del arreglo (tabla) en la posición [14] es: %d, ", tabla[14]);

   printf("\n\n Programa finalizado \n ");  

   return 0;

}








