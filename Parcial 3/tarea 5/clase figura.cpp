#include<iostream>
#include<cmath>
using namespace std; 

template <typename T>
class figura{
	protected: 
		T base,lado, lado1, lado2; 
		T altura; 
		T area, perimetro; 
	public:
		virtual void calcArea()=0;
		virtual void calcPeri()=0;	
		virtual void setbase(T b){
			base=b;}
		virtual T getbase(){
			return base;}
		virtual void setaltura(T s){
			altura = s; }
		virtual T  getaltura(){
			return altura;}		
};
/*
template <typename T>
class figura: public delimitar figura{
};*/

template <typename T>
class Cuadrado: public figura<T>{
	public:
		Cuadrado(void){;}
		Cuadrado( T l){
			this->base = l; 
		}
	 
		void calcArea(){
			this->area= this->getbase()*this->getbase();
			cout<<this->area;
		}
		void calcPeri(){
			this->perimetro= this->getbase()*4;
			cout<<this->perimetro;
		}
};
template <typename T>
class Rectangulo: public figura<T>{
	public:
		Rectangulo(void){;}
		Rectangulo(T b, T a){
			this->base= b; this->altura =a;
		} 
		void calcArea(){
			this->area=this->getbase()*this->getaltura();
			cout<<this->area;
		}
		void calcPeri(){
			this->perimetro=2*this->getbase() + 2*this->getaltura(); 
			cout<<this->perimetro;
		}
};
template <typename T>
class Triangulo: public figura<T>{
	private: 
	double hipotenusa;
	double gethipo(){
		this->hipotenusa = sqrt(this->getbase()*this->getbase() + this->getaltura()* this->getaltura());
		return this->hipotenusa;
	}
	
	public:
		Triangulo(void){;}
		Triangulo(T b, T a){
			this->base = b; 
			this->altura = a; 
		} 
		void calcArea(){
			this->area= (this->getbase()*this->getaltura())/2;
			cout<<this->area;
		}
		void calcPeri(){
			this->perimetro= this->getbase()+this->getaltura()+this->gethipo();
			cout<<this->perimetro;
		}

};
template <typename T>
class Rombo: public figura<T>{
	public:
	Rombo(){;}
	Rombo(T b, T a, T l){
			this->base=b; this->lado= a; this->lado=l;
		}
		void calcArea(){
			this->area= (this->getbase()*this->getaltura())/2;
			cout<<this->area; 
		}
		void setLado(double l){
			this->lado=l; }
		T getLado(){
			return this->lado;
		}
		void calcPeri(){
			this->perimetro=4*this->getLado();
			cout<<this->perimetro;
			}	
};
template <typename T>
class Romboide: public figura<T>{
	public:
		Romboide(){;}
		void calcArea(){
			this->area=this->getbase()*this->getaltura();
			cout<<this->area;
		}
		void calcPeri(){
			this->perimetro=2*this->getbase()+2*this->getaltura();
			cout<<this->perimetro;
		}		
};
template <typename T>
class Trapecio: public figura<T>{
	public: 
		Trapecio(){;}
		void setlado(T l){
			this->lado=l;
		}
		void setlado1(T l1){
			this->lado1=l1;
		}
		void setlado2(T l2){
			this->lado2=l2;
		}		
		T getlado1(){
			return this->lado1;
		}
		T getlado2(){
			return this->lado2;
		}
		T getlado(){
			return this->lado;
		}
		void calcArea(void){
			this->area=(this->getaltura()*(this->getlado1()+this->getlado2()))/2;
			cout<<this->area;
		}
		void calcPeri(void){
			this->perimetro=this->getlado1()+this->getlado2()+2*this->getlado();
			cout<<this->lado;
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
	ro1.setaltura(350054659); ro1.setbase(65434533);
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
