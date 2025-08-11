template<typename X>
class estructuraDatos{
	public:
		virtual void insertar(X x)=0;
		virtual X extraer(void)=0; 
		virtual void imprimir(void)=0; 
};
template<typename X>
class nodo{
	public:
		X dato; 
		nodo *siguiente;
};

