#include <stdio.h>

int main()

{

   int x, tabla[100];

   printf("\n Programa que obtiene los 100 primeros n�meros enteros ");

   printf("\n y los almacena en un arreglo, tambi�n los imprime en pantalla \n\n ");

   // Asignaci�n de datos al arreglo

   for (x=0;x<100;x++) //x++ es un incremento en 1, es decir; x= x+1;

   {

       tabla[x]=x;

   }



   //Impresi�n del arreglo

   for (x=0;x<100;x++)

   {

       printf("%d, ",tabla[x]); // Poner \n si se quiere imprimir en forma vertical

   }

   printf("\n El valor del arreglo (tabla) en la posici�n [14] es: %d, ", tabla[14]);

   printf("\n\n Programa finalizado \n ");  

   return 0;

}








