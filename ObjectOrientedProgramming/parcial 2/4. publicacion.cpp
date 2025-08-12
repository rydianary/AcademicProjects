#include<iostream>
#include<string>
using namespace std; 

class publicacion{
	private: 
		string titulo; float precio;
	public:
		publicacion(){
			precio; 
			titulo;
		}
		void setTitutlo(string t){
			titulo=t;
		}
		void setPrecio(float p){
			precio=p;
		}
		string getTitulo(){
			return titulo;
		}
		float getPrecio(){
			return precio;
		}

};

class libro: public publicacion{
	private: 
		int paginas;
	public:		
		void setPaginas(int pag){
			paginas=pag;
		}
		int getPaginas(){
			return paginas;
		}
		void printdatos(){
			cout<<"\n\nDATOS: \n";
			cout<<"\nTitulo: "<<getTitulo();
			cout<<"\nPrecio: "<<getPrecio();
			cout<<"\nNumero de paginas: "<<getPaginas();
		}

};

class libroUSB: public publicacion{
	private: 
			float tiempor;
	public:
		void setTiempor(float tiem){
			tiempor=tiem;
		}
		float getTiempor(){
			return tiempor;
		}
		void printdatos(){
			cout<<"\n\nDATOS: \n";
			cout<<"\nTitulo: "<<getTitulo();
			cout<<"\nPrecio: "<<getPrecio();
			cout<<"\nTiempo de reproduccion (seg): "<<getTiempor();
		}
};

int main(){
	libro a; 
	a.setPaginas(250);
	a.setTitutlo("Romeo y Julieta");
	a.setPrecio(250.84);
	a.printdatos();
	
	libroUSB b; 
	b.setTitutlo("El arte de la guerra");
	b.setPrecio(158.77);
	b.setTiempor(355);
	b.printdatos();
	
}
