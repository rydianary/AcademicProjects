#include<iostream>
using namespace std; 
//motor ruedas y ventanas no suelen derivar una de la otra, sin embargo
//si se usan todas al mismo tiempo es posible crear un transporte terreste
class motor{
	public: 
		motor( void){
			cout<<"motor encendido\n";
		}
		void arranque(){
			cout<<"\nListo para avanzar.\n";
		}
		void correr(int x){
			cout<<"\nCorriendo a "<<x<<"km/h\n";
		}
		void apagado(){
			cout<<"motor "<<"apagado.\n";}
		
		~motor(){
			cout<<"\nYa no sirve el motor D: \n";
		}	
};

class rueda{
	private: 
		int i; 
	public:
		rueda(void){
			cout<<"4 ruedas instaladas";
		}
		~rueda(void){
			cout<<"\nLlantas lisas :c ";
		}
		inflar(int rueda){
			for(i=1;i<rueda;i++){
				cout<<"inflando rueda ... "<<i<< "\n";
		}
	}
		desinflar(int PSI){
			for(i=1;i<PSI;i++){
				cout<<"desinflando rueda... "<<i<< "\n";
		}
		}  

};

class ventana{
	private:
		int i;
	public:
	ventana(){
		cout<<"\n2 ventanas detectadas";
		} 
	abrirv(int v){
		for(i=1; i<=v; i++){
			cout<<"Bajando vidrio " <<i<<'\n';
		}
		
	}
	cerrarv(int v){
		for(i=1; i<=v; i++){
			cout<<"Subiendo vidrio "<<i<<'\n';
		}
		
	}
	~ventana(){
		cout<<"\nvidrios rotos </3 ";
	}
	
};
class puerta{
	public: 
	puerta(){
		cout<<"\n2  puertas ensambladas";
	}
	abrirp(){
		cout<<"Puertas abiertas\n";
	}
	cerrarp(){
		cout<<"Puertas cerradas\n";
	}
	~puerta(){
		cout<<"\npuertas desprendidas.";
	}
};

class coche: public motor, public rueda, public ventana, public puerta{
};

int main(void){
	cout<<"Ensamble COCHE SEDAN\n";
	coche sedan;
	sedan.arranque();
	sedan.abrirp();
	sedan.inflar(5);
	sedan.correr(250);
}
	

