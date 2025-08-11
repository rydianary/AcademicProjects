#include<iostream>
#include<cmath>
using namespace std; 

class Punto{
	private: 
	int x,y;float k;
	public: 
		Punto(int a, int b){
			x=a;
			y=b;
			
		}
		float distanciaEuclidiana(){
			k=(sqrt((pow(x-1,2))+(pow(y-1,2))));
			return (k);	
		}
		float distanciaManhattan(){
			k=(abs(x-1)+abs(y-1));
			return k;
		}
		
		

};

int main(){
	Punto p1_p2(5,4);
	cout<<"Distancia entre dos puntos\n";
	cout<<"Punto base (1, 1)\n";
	cout<<"d. Euclidiana: "<<p1_p2.distanciaEuclidiana()<<'\n';
	cout<<"d. Manhattan: "<<p1_p2.distanciaManhattan()<<'\n';
}
