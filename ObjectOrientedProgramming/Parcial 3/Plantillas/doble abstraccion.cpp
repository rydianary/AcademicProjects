#include<iostream>
#include<string>
using namespace std;

//creacion de la plantilla 
//el tipo sera el elemento generico
template<typename tipo>
class prueba{
	public: 
		tipo informacion;
};

int main(){
	prueba<int> obj1;
	prueba<int> obj2;
	prueba<string> obj3;
}
