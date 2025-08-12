#include<iostream>

/* la historia de la evolucion del humano
empezo siendo un animal, posteriormente se volvio un chango 
y carvernicola y humano consecuentemente

entre las cosas que cambiaban era su nivel de inteligencia
sus patas (que se volvieron manos eventualmente)*/
using namespace std; 
class Animal{
	private:
		int nacimiento;
	protected:
		int inteligencia; 
		int patas;
		int manos;
	public: 
		Animal(){
		}

		Animal( int p, int m){
			patas = p; 
			manos = m; 
		}
		void sonido(){
			cout<<"Animal sound**\n";
		}
	void setPatas(int p){
		this->patas=p; 
	}
	int getPatas(){
		return this->patas; 
	}

	void setManos(int m){
		this->manos=m; 
	}
	int getManos(){
		return this->manos; 
	}
	int AnioNacer(int n){
		this->nacimiento=n;
	}
	void movimiento(){
		cout<<"Moviendose \n";
	}

};

class Chango: public Animal{
	public: 
		void sonido(){
			cout<<" Uh Uh Ah Ah\n";
		}
		void movimiento(){
			cout<<" Trepar y brincar \n";
		}

};

class Cavernicola: public Chango{
	public: 
		void sonido(){
			cout<<" Ho-ho-la\n";
		}
		void movimiento(){
			cout<<" Caminar en 4 patas \n";
		}
};

class Humano: public Cavernicola{
	public:
		void sonido(){
			cout<<"Hola buenos dias \n";
		}
		void movimiento(){
			cout<<"Caminar en 2 patas \n";
		}
};

int main(){
	
	cout<<"Humano: \n";
	Humano juan;
	juan.setManos(2);
	juan.setPatas(2);
	cout<<"\nmanos:"<<juan.getManos();
	cout<<"\npatas:"<<juan.getPatas();
	cout<<"Movimiento: ";
	juan.movimiento();
	cout<<"Sonido: "; juan.sonido();
	
	Chango cesar; 
	cout<<"\nChango: ";
	cesar.setManos(0);
	cesar.setPatas(4);
	cout<<"\nmanos:"<<cesar.getManos();
	cout<<"\npatas:"<<cesar.getPatas();
	cout<<"\nMovimiento: ";
	cesar.movimiento();
	cout<<"Sonido: ";
	cesar.sonido();
	
	cout<<"\nCavernicola";
	Cavernicola lucy;
	lucy.setManos(2);
	lucy.setPatas(2); 
	cout<<"\nmanos:"<<lucy.getManos();
	cout<<"\npatas:"<<lucy.getPatas();
	cout<<"\nMovimiento: ";
	lucy.movimiento();
	cout<<"Sonido: ";
	lucy.sonido();
	
	cout<<"\nAnimal"; 
	Animal a1;
	cout<<"\nMovimiento: ";
	a1.movimiento();
	cout<<"Sonido: ";
	a1.sonido(); 
	
	
}
