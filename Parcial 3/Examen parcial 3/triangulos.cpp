#include<iostream>
using namespace std;

template <typename T>
class Poligono{
	protected: T perimetro; 
	public: 
	virtual void Perimetro(void)=0;	
};
template <typename T>
class Triangulo: public Poligono<T>{
	protected: 
		T lado1, lado2, lado3; 
	public:
		Triangulo(void){;} 
		Triangulo(T a, T b, T c){
			this->lado1=a; this->lado2=b; this->lado3=c;
		}
		void Perimetro(void){
			this->perimetro=lado1+lado2+lado3; 
		}
		void setL1(T a){this->lado1=a;}
		void setL2(T b){this->lado2=b;}
		void setL3(T c){this->lado3=c;}
		T getL1(void){return this->lado1;}
		T getL2(void){return this->lado2;}
		T getL3(void){return this->lado3;}
		T getP(void){return this->perimetro;}
};
template <typename T>
class Equilatero: public Triangulo<T>{
	public: 
		Equilatero(void){;}
		Equilatero(T a){this->lado1=a;}
		void Perimetro(void){
			this->perimetro=this->getL1()*3;
		}
};
template<typename T>
class Isoceles: public Triangulo<T>{
	public:
		Isoceles(void){;}
		Isoceles(T igual, T dif){
			this->lado1=igual; this->lado2=dif;
		}
		void Perimetro(void){
			this->perimetro=this->getL1()*2+this->getL2();
		}
};
template<typename T>
class Escaleno: public Triangulo<T>{
	public:
		Escaleno(void){;}
		Escaleno(T a, T b, T c){
			this->lado1=a; this->lado2=b; this->lado3=c;
		}
		void Perimetro(void){
			this->perimetro=this->getL1()+this->getL2()+this->getL3();
		}
};

int main(void){
	cout<<"Perimetro de figuras Triangulares\n";
	 
	cout<<"\n\nTriangulo isoceles";
	Isoceles<int> t2;
	t2.setL2(5);t2.setL1(4);
	cout<<"\nLado a: "<<t2.getL1()<<"\nLado b: "<<t2.getL2();
	t2.Perimetro(); cout<<"\nPerimetro: "<<t2.getP();

	cout<<"\n\nTriangulo equilatero";
	Equilatero<double> t1;
	t1.setL1(2.23423);
	cout<<"\nLado a: "<<t1.getL1(); t1.Perimetro();
	cout<<"\nPerimetro: "<<t1.getP();
	
	cout<<"\n\nTriangulo escaleno";
	Escaleno<float> t3; 
	cout<<"Lado";
	t3.setL1(5.1); t3.setL2(7); t3.setL3(6.01);
	cout<<"\nLado a: "<<t3.getL1()<<"\nLado b: "<<t3.getL2()<<"\nLado c: "<<t3.getL3();
	t3.Perimetro(); cout<<"\nPerimetro: "<<t3.getP();
	
}
