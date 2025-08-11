#include<iostream>
#include<iostream>
#include<cmath>
using namespace std; 

class Punto{
	private: 
	int x1,x2,y1,y2;float k;
	public: 
		Punto(int a, int b,int c, int d){
			x1=a;
			y1=b;
			x2=c;
			y2=d;
		}
		float distanciaEuclidiana(){
			k=(sqrt((pow(x2-x1,2))+(pow(y2-y1,2))));
			return (k);	
		}
		float distanciaManhattan(){
			k=(abs(x2-x1)+abs(y2-y1));
			return k;
		}
		
		

};

int main(){
	Punto p1_p2(5,4,1,1);
	cout<<"Distancia entre dos puntos\n";
	cout<<"d. Euclidiana: "<<p1_p2.distanciaEuclidiana()<<'\n';
	cout<<"d. Manhattan: "<<p1_p2.distanciaManhattan()<<'\n';
}
