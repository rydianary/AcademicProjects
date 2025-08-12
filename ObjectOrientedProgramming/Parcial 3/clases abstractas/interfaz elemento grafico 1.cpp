#include<iostream>
#include<string>
using namespace std; 
class ElementoGraficoGenerico{
	public: 
		virtual void setColor(double r, double g, double b)=0; 
		virtual void setPos(double xpos, double ypos)=0;
		virtual void setLabel(string lb)=0; 
		virtual void onClickPressed()=0; 
};
class LineaTexto: public ElementoGraficoGenerico{
	//implementaccion especifica de metodos virutales heradados
};
class BotonOkCancel: public ElementoGraficoGenerico{
	//implementaccion especifica de metodos virutales heradados
};
class CheckBox: public ElementoGraficoGenerico{
	//implementaccion especifica de metodos virutales heradados
};

int main(){
}
