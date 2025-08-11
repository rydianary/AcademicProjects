#include<iostream>
using namespace std; 
//funcion que sirve para todo tipos de datos
template <typename T>
T myMax(T x, T y){
	return(x>y)? x:y;
	
/* if(x>y) return x;
	else   return y;*/
}

int main(){
	//se llama la funcion con numeros enteros 
	cout<<myMax<int>(3,7)<<"\n";
	//con numeros flotantes
	cout<<myMax<float>(3.0, 7.0)<<"\n";
	//con caracteres
	cout<<myMax<char>('g','e')<<"\n";
}
