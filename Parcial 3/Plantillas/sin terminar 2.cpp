#include<iostream>
#include<string>
using namespace std;

template<typename X, typename Y, typename Z>
class pruebaParametro{
	public:
		//constructores
		pruebaParametro(){}
		pruebaParaemtro(X a, Y b, Z c){
			x=a;
			y=b;
			z=c;
		}
	private: 
		X x;
		Y y;
		Z z;
		
};

class prueba{
	prueba(){
	}
};

int main(){
	pruebaParametro<int, string, float> objeto1(); 
	pruebaParametro<int, string, float> objeto2(); 
	prueba objeto3();
	pruebaParametro<float, int, prueba> objeto4(5.5,9, objeto3());
}
