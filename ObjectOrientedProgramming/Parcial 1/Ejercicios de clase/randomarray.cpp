#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std; 

class operacionesArreglo{
	private:
		int i,j, k, sum=0, multi=1;
		int arreglo[5]; int arrpos[5]; int arrneg[5];
		
		void mostrar(){
			for(i=0;i<5;i++){
				while(i=0){
					cout<<"\nPositivos: \n";
				}
				cout<<arrpos[i];
				while(i=0){
					cout<<"\nNegativos: \n ";
				}
				cout<<arrneg[i];
			}
		}
	public:
		operacionesArreglo(){
			srand(time(0));
			for(i=0;i<5;i++){
				arreglo[i]=(rand()%10)-5;
			}
		}
		~operacionesArreglo(){
			cout<<"\n\nArreglo: ";
			for(i=0;i<5;i++){
				cout<<arreglo[i]<<" ";}
		}
		
		void pos_neg(){
			for(i=0; i<5;i++){
				if(arreglo[i]>0){
					arrpos[i]=arreglo[i];		
				}
				else if(arreglo[i]==0){
					cout<<"\nCERO: 0";
				}
				else{	
					arrneg[i]=arreglo[i];
					
				}
			}
		}

			void suma(){
				for(i=0;i<5;i++){
					sum+=arreglo[i];
				}
				cout<<"\nSuma de elementos: "<<sum;
			}
			void producto(){
				for(i=0;i<5;i++){
				multi*=arreglo[i];	
				}
				cout<<"\nMultiplicacion de elementos: "<<multi;
			}
			
		
		
		

};

int main(){
	operacionesArreglo obj1;
	obj1.pos_neg();
	obj1.suma();
	obj1.producto();
	obj1.mostrar();
}
