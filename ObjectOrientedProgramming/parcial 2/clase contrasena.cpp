#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std; 

class contrasena{
	private:
		int i, longitud=8;
		string password[longitud];
		string mayusculas="ABCDEFJHIJLMNOPQRSTUVWXYZ";
		string minusculas="abcdefghijklmnoprstuvwxyz";
		string numeros="0123456789";
		
		void generarPassword(){
			for(i=0; i<longitud;i++){
				password[i]=caracteres[rand()%45];
				cout<<password[i];
		}
		}
	public: 
		Contrasena(){ 
		generarPassword();
		}
		Contrasena(int n){
			longitud = n; 
			generarPassword();
		}		
};
