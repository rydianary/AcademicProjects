#include<iostream>
#include<string>
using namespace std; 

class fecha{
	private: int dia, mes, anio, aniosb;
	int const diasmes[12]={31,28,31,30,31,30,31,31,30,31,30,31}; 
	int const diasmesb[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	int const t[12]={0,3,2,5,0,3,5,1,4,6,2,4};
	string meses[12]={"enero", "febrero", "marzo","abril","mayo","junio","julio","agosto","septiembre","octubre", "noviembre","diciembre"};
	string const diassemana[7]={"domingo","lunes","martes","miercoles","jueves","viernes","sabado"};
	public:	
		fecha(void){
			this->dia=1; this->mes=1; this->anio=1900;
		}
		fecha(int x, int y, int z){
			this->dia=x; this->mes=y; this->anio=z;
		}
		void leer(int x, int y, int z){
			if((x>0 && x<=32)&&(y>0 && y<=12) && (z>=1900 && z<=2050)){
				this->dia=x; this->mes=y; this->anio=z;
			}
			else{
				this->dia=1; this->mes=1; this->anio=1900;
			}
		}
		int  getfecha(){
			fecha(this->dia, this->mes, this->anio);
		}
		int getdia(){
			return this->dia;}
		int getmes(){
			return this->mes;}
		int getanio(){
			return this->anio;	}
		int contarleaps(){
			if(this->mes<=2){
				aniosb--;
			}
			return aniosb/4-aniosb/100+aniosb/400;
		}
		void bisiesto(void);
		int diasMes(int x);
		int valida();
		void formatoCorto();
		int diasTranscurridos() const;
		string diaSemana();
		void formatoLargo();
		int diasEntre(const fecha &afo);
		void siguiente();
		void anterior(); 
		void igualQue( const fecha &afo);
		void menorQue( const fecha &afo); 
		void mayorQue( const fecha &afo);  
};
void fecha::bisiesto(void){
	if(anio%4==0){
		cout<<"El anio es bisiesto\n";
	}
	else{
		cout<<"El anio no es bisiesto\n";
	}
}
int fecha:: diasMes(int x){
	if(this->anio%4==0){
		return diasmesb[x-1];
	}
	else{
	return diasmes[x-1];}
	
}
int fecha::valida(){
	if((dia>0 && dia<=32)&&(mes>0 && mes<=12) && (anio>=1900 && anio<=2050)){
		fecha(this->dia, this->mes, this->anio);
	}
	else{
		fecha(this->dia=1,this->mes=1, this->anio=1900);
	}	
}

void fecha::formatoCorto(){
	cout<<"fecha: ("<<this->getdia()<<"-"<<this->getmes()<<"-"<<this->getanio()<<")\n";
}
int fecha::diasTranscurridos() const{
	int days=0;
	for(int i=1900;i<anio;i++){
		if(anio%4==0){
			days+=366;
		}
		else days+=365;
	}
	return days;}
string fecha::diaSemana(){
	return diassemana[diasTranscurridos()%7];
}
void fecha::formatoLargo(){
	cout<<this->diaSemana()<<" "<<this->dia<<" de "<<meses[this->mes-1]<<" de "<<this->anio<<"\n";
}
int fecha::diasEntre(const fecha &afo){
	int r;
	r=this->diasTranscurridos()- afo.diasTranscurridos();
	return (r>0? r:-r);
}
void fecha::siguiente(){
	if(this->dia==31 && this->mes==12){
		cout<<"El dia siguiente es: 1-1-"<<this->anio+1<<"\n";
	}
	else if(this->dia == diasmes[this->mes-1]){
		cout<<"El dia siguiente es: 1-"<<this->mes+1<<"-"<<this->anio<<"\n";
	}
	else{cout<<"El dia siguiente es: "<<this->dia+1<<"-"<<this->mes<<"-"<<this->anio<<"\n";}
}
void fecha::anterior(){
	if(this->dia==1 && this->mes==1){
		cout<<"El dia anterior es: 31-12-"<<this->anio-1<<"\n";
	}
	else if(this->dia == diasmes[this->mes-1]){
		cout<<"El dia anterior es: "<<diasmes[this->mes-2]<<"-"<<this->mes<<"-"<<this->anio<<"\n";
	}
	else{
		cout<<"El dia anterior es: "<<this->dia-1<<"-"<<this->mes<<"-"<<this->anio<<"\n";
	}
}
void fecha::igualQue(const fecha &afo){
	if(this->diasTranscurridos() == afo.diasTranscurridos()){
		cout<<"Las fechas son iguales. \n";}
	else {
		cout<<"Las fechas son diferentes.\n";	}
}
void fecha::menorQue(const fecha &afo){
	if(this->diasTranscurridos()<afo.diasTranscurridos()){
		this->formatoCorto(); cout<<" es anterior\n"; 
	}
	else if (this->diasTranscurridos() == afo.diasTranscurridos()){
		cout<<"Las fechas son iguales\n";}
	else{
		this->formatoCorto(); cout<<" no es anterior \n"; 
	}
}
void fecha::mayorQue(const fecha &afo){
	if(this->diasTranscurridos()>afo.diasTranscurridos()){
		this->formatoCorto(); cout<<" es la mas reciente "; 
	}
	else if (this->diasTranscurridos() == afo.diasTranscurridos()){
		cout<<"Las fechas son iguales\n";}
	else{
		this->formatoCorto(); cout<<" no es la mas reciente "; 
	}
}
int main(void){
	fecha cumple1;
	fecha cumple2;
	cumple1.leer(2,5,2012);
	cumple2.leer(31,12,2015);
	cumple1.valida();
	cumple1.formatoCorto();
	cout<<"El 2-5-2012 fue "<<cumple1.diaSemana()<<"\n";
	cumple1.formatoLargo();
	cumple1.bisiesto();
	cout<<"El mes de febrero tiene "<<cumple1.diasMes(2)<<" dias\n";
	cout<<"\nDias desde 1-1-1900 : "<<cumple1.diasTranscurridos()<<" dias\n";
	cout<<"\nDias entre 2-5-2012 y 31-12-2015: "<<cumple1.diasEntre(cumple2)<<"\n";
	cumple2.formatoCorto();
	cumple2.siguiente();
	cumple2.anterior();
	cout<<"Son iguales? ";cumple1.igualQue(cumple2);
	cout<<"\n2-5-2012 es anterior? ";cumple1.menorQue(cumple2);
	cout<<"\n2-5-2012 es mas reciente? " ;cumple1.mayorQue(cumple2);
}


