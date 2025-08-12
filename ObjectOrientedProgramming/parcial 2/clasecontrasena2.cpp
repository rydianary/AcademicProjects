#include<iostream>
#include<string>
#include<stdlib.h>
#include <stdio.h>

using namespace std; 

class Contrasena{
	private: 
	int i, tamano, longitud=8, upper=0, lower=0, number=0; 
	//char caracteres[45]={'1','2','3','4','5','6','7','8','9','0','q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','A','B','C','D','E','F','G','H','I'};
	string caracteres={"123456789qwertyuuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"};
	string str[100];
	void generarpassword(){
		cout<<"\nPassword\n";
	//	srand(time(0));
		for(i=0; i<longitud;i++){
			str[i]=caracteres[rand()%62];
			cout<<str[i];
		}
	}
	
	void printesFuerte(){
		if(esFuerte()==1) cout<<"\n -Contrasena fuerte";
		else cout<<"\n -Contrasena debil";
	}
	
	public: 
	Contrasena(){
		generarpassword();
	    printesFuerte();
	}
	Contrasena(int n){
		longitud=n;
		generarpassword();
		printesFuerte();
	}
	void setLongitud(int n){
		longitud=n; 
	}
	int getLongitud(){
		return longitud; 
	}
	void setPassword(string input[100]){
		str[100]=input[100];
	}
	string getPassword(){
		return str[100];
	}
	int esFuerte();
	
};

int Contrasena::esFuerte(){
	for(i=0; i<longitud;i++){
		
        if (str[i] >= "A" && str[i] <= "Z")
            upper++;
        else if (str[i] >= "a" && str[i] <= "z")
            lower++;
        else if (str[i]>= "0" && str[i]<= "9")
            number++;
        else if(upper>2 && lower>1 && number>5) return 1;
        else return 0; 
		}			
			}


int main(){
	int size;
	cout<<"\n Arreglo de passwords\n Size: "; cin>>size; 
	
	Contrasena passwords[size];
	for(int i=0; i<size; i++){
		passwords[i]=Contrasena(rand()%35);
	    passwords[i].esFuerte();

	}

	
	
}