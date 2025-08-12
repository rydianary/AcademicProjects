
#include<iostream>
#include<cmath>
using namespace std; 

class figura{
	protected: 
		double base,lado, lado1, lado2; 
		double altura; 
		double area, perimetro; 
	public:
		virtual void calcArea()=0;
		virtual void calcPeri()=0;	
		void setbase(double b){
			base=b;}
		virtual double getbase(){
			return base;}
		virtual void setaltura(double s){
			altura = s; }
		virtual double getaltura(){
			return altura;}		
};

template <typename T>
class Cuadrado: public figura{
	public:
		Cuadrado(void){;}
		Cuadrado( T l){
			base = l; 
		}
	 
		void calcArea(){
			area= getbase()*getbase();
			cout<<area;
		}
		void calcPeri(){
			perimetro= getbase()*4;
			cout<<perimetro;
		}
};
template <typename T>
class Rectangulo: public figura{
	public:
		Rectangulo(void){;}
		Rectangulo(T b, T a){
			base= b; altura =a;
		} 
		void calcArea(){
			area=getbase()*getaltura();
			cout<<area;
		}
		void calcPeri(){
			perimetro=2*getbase() + 2* getaltura(); 
			cout<<perimetro;
		}
};
template <typename T>
class Triangulo: public figura{
	private: 
	double hipotenusa;
	double gethipo(){
		hipotenusa = sqrt(getbase()*getbase() + getaltura()* getaltura());
		return hipotenusa;
	}
	
	public:
		Triangulo(void){;}
		Triangulo(T b, T a){
			base = b; 
			altura = a; 
		} 
		void calcArea(){
			area= (getbase()*getaltura())/2;
			cout<<area;
		}
		void calcPeri(){
			perimetro= getbase()+getaltura()+gethipo();
			cout<<perimetro;
		}

};
template <typename T>
class Rombo: public figura{
	public:
	Rombo(){;}
	Rombo(T b, T a, T l){
			base=b; lado= a; lado=l;
		}
		void calcArea(){
			area= (getbase()*getaltura())/2;
			cout<<area; 
		}
		void setLado(double l){
			lado=l; }
		double getLado(){
			return lado;
		}
		void calcPeri(){
			perimetro=4*getLado();
			cout<<perimetro;
			}	
};
template <typename T>
class Romboide: public figura{
	public:
		Romboide(){;}
		void calcArea(){
			area=getbase()*getaltura();
			cout<<area;
		}
		void calcPeri(){
			perimetro=2*getbase()+2*getaltura();
			cout<<perimetro;
		}		
};
template <typename T>
class Trapecio: public figura{
	public: 
		Trapecio(){;}
		void setlado(T l){
			lado=l;
		}
		void setlado1(T l1){
			lado1=l1;
		}
		void setlado2(T l2){
			lado2=l2;
		}		
		T getlado1(){
			return lado1;
		}
		T getlado2(){
			return lado2;
		}
		T getlado(){
			return lado;
		}
		void calcArea(void){
			area=(getaltura()*(getlado1()+getlado2()))/2;
			cout<<area;
		}
		void calcPeri(void){
			perimetro=getlado1()+getlado2()+2*getlado();
			cout<<lado;
		}	
};

int main(){
	cout<<"\n\nTriangulo ";
	Triangulo <double>t1;
	t1.setaltura(2);
	t1.setbase(5);
	cout<<"\nArea: ";
	t1.calcArea();
	cout<<"\nPerimetro: ";
	t1.calcPeri();
	
	cout<<"\n\nCuadrado ";
	Cuadrado <double>c1;
	c1.setaltura(2);
	c1.setbase(5);
	cout<<"\nArea: ";
	c1.calcArea();
	cout<<"\nPerimetro: ";
	c1.calcPeri();
	
	cout<<"\n\nRectangulo ";
	Rectangulo <int>r1;
	r1.setaltura(2);
	r1.setbase(5);
	cout<<"\nArea: ";
	r1.calcArea();
	cout<<"\nPerimetro: ";
	r1.calcPeri();
	
	cout<<"\n\nRomboide ";
	Romboide <long>ro1;
	ro1.setaltura(2.131234); ro1.setbase(3.1241212);
	cout<<"\nArea: ";
	ro1.calcArea();
	cout<<"\nPerimetro: ";
	ro1.calcPeri();
	
	cout<<"\n\nTrapecio ";
	Trapecio <float>tra1; 
	tra1.setaltura(12); tra1.setlado(6.5); tra1.setlado1(5); tra1.setlado2(7);
	cout<<"\nArea: ";
	tra1.calcArea();
	cout<<"\nPerimetro: ";
	tra1.calcPeri();
}
