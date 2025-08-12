class poligono{
	int num_lados; 
	public: 
		//metodo implementado
		void  setNumLados(int n){
			num_lados=n; 
		}
		virtual double calcularArea()=0;
		virtual double calcularPerimetro()=0;
};

class triangulo: public poligono{
	public: 
		double calcularArea(){
		}
		double calcularPerimetro(){
		}
};

class hexagono: public poligono{
	public: 
		double calcularArea(){
		}
		double calcularPerimetro(){
		}
};

int main(){
	
}
