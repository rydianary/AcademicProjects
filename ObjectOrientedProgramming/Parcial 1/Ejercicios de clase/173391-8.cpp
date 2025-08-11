#include<iostream>
#include<cmath>
using namespace std; 
class calculosEstadisticos{
	int n,i; float sum=0, media, desvio, error,k; 
	int data[100];
	public:
		int get_n(){
			cout<<"Ingrese el numero de datos a trabajar: ";
			cin>>n;
			return n;
		}
		void media_ar(){
			for(i=0;i<n;i++){
				cout<<"Dato "<<i<<": ";
				cin>>data[i];
				sum+=data[i];
				media=sum/n;
			}
			cout<<"\nMedia aritmetica: "<<media;
		}
		void desviacion(){
			for(i=0;i<n;i++){
				k+=pow((data[i]-media), 2);
				desvio=k/n;			
			}
			cout<<"\ndesviacion aritmetica: "<<desvio;
		}
		void errorstandar(){
			error=(desvio/sqrt(n));
			cout<<"\nError estandar: "<<error;
		}
		
};

int main(){
	calculosEstadisticos calif;
	calif.get_n();
	calif.media_ar();
	calif.desviacion();
	calif.errorstandar();
}

