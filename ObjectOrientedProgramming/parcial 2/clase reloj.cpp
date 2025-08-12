#include<iostream>
#include<ctime>
using namespace std; 

class reloj{
	private: 
		int hr, min, seg;
	
	public: 
		reloj(){;}
		
		void setSegundos(int s){
			this->seg=s;
		}
		void setMinutos(int m){
			this->min=m; 
		}
		void setHoras(int h){
			this->hr=h;
		}
		int getSegundos(){
			return this->seg;
		}
		int getMinutos(){
			return this->min; 
		}
		int getHoras(){
			return this->hr; 
		}
		
		void IniciarCronometro(){
			this->hr=0; this->min=0; this->seg=0;
				
		}
		void ponerAcero(){
		
			this->hr=0; this->min=0; this->seg=0;
		}
		void ponerHora(int h, int m, int s){
			this->hr=h; this->min=m; this->seg=s;
		}
		void Incremento(){
			if(this->min+=5){
				display();
				cout<<"	5 min!! *BEEP* *BEEP*\n";
			}
			else{
				display();
			}
		}
		void finalizacion(){
			cout<<"\nHas alcanzado 23:59:59 \n*REINICIANDO*";
			hr=0; min=0; seg=0;
		}
		void display(){
			if(this->hr==0 && this->min==0 && this->seg==0){
				cout<<"\n00:00:00\n";
			}
			else{
				cout<<"\n"<<hr<<":"<<min<<":"<<seg<<"\n";
			}
			
		}
};

int main(){
	reloj r1, r2, r3; 
	r1.setHoras(15);
	r1.setMinutos(25);
	r1.setSegundos(12);
	cout<<"\nr1: ";
	r1.display();
	r1.Incremento();
	
	cout<<"\nr2 inicio: ";	
	r2.IniciarCronometro();
	r2.display();
	cout<<"\nr2 setting: ";
	r2.ponerHora(22, 21, 20);
	r2.display();
	cout<<"\nr2 reset: ";
	r2.ponerAcero();
	r2.display();

	cout<<"\nr3: ";
	r3.finalizacion();
	r3.display();

	
}

