#include<iostream>
using namespace std; 
class Student{
	int real; 
	int imag;
	
	public:
		Complex(int r, int i){
			real = r; 
			imag = i; 
		}
		
		int get_real(){
			return real;
		}
		int get_imag(){
			return imag;
		}
		void add(Complex c1){
			cout<<c1.get_real()+real<<"+i"<<c1.get_imag()+imag<<'\n';
		}
		void difference(Complex c1){
			cout<<real-c1.get_real()<<"+i"<<imag-c1.get_imag()<<'\n';
		}

};

int main(){
	Complex c1(4,5);
	Complex c2(2,3);
	c1.add(c2);
	c1.difference(c2);
	return 0;
}
