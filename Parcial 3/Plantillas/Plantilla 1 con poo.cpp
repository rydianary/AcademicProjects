#include<iostream>
using namespace std; 

template<class T>
class miClase{
	private:
		T a, b;
	public: 
	//constructor
	miClase(T first, T second){this->a; this->b=second;}
	
	T getMaxValor(){return(a>b? a:b);}
};

int main(){
	miClase <int> objeto1(100,75);
	cout<<"Maximo de 100 y 75 = "<<objeto1.getMaxValor()<<"\n";
	miClase<char> objeto2('A', 'a');
	cout<<"Maximo de 'A' y 'a' = "<< objeto2.getMaxValor()<<'\n';
	
	
}
