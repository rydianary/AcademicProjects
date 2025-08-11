#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std; 

template<typename T>
class Matriz{
	private:
		T mat[10][10];
		T sumad=0; 
		int size;
	public:
		void setMatriz(){
	        srand(time(NULL));
	        for(int i=0;i<size;i++){
	            for(int j=0;j<size;j++){
	            	mat[i][j]=1+rand() %10;
	        }
		}}
		void setCell(int i, int j, T c){
	        mat[i][j]=c;
	        }
		
		void setsize(int n){this->size=n;}
		void sumaDiagonal(){
			for(int i=0; i<size; i++){
					sumad+=this->mat[i][i];
				}cout<<" Suma diagonal: "<<this->sumad;
			}
		void TsupSuma(){
			T sumasup=0;
			for(int i=0; i<size;i++){
				for(int j=0; j<size;j++){
					if(j<=i){
						sumasup+=this->mat[i][j];
					}
				}
			} sumasup-=this->sumad;
			 cout<<" \nSuma Diagonal superior: "<<sumasup;
		}
		void TinfSuma(){
			T sumainf=0; 
			for(int i=0; i<size;i++){
				for(int j=0; j<size; j++){
					if(j<=i){
						sumainf+=mat[i][j];
					}
				}
			}
			sumainf-=this->sumad;
			cout<<"\nSuma Diagonal inferior: "<<sumainf;
		}
		void Cell5a10(){
			T suma5a10;
			for(int i=0; i<size;i++){
				for(int j=0; j<size; j++){
					if(mat[i][j]>5 && mat[i][j]<10){
						suma5a10+=mat[i][j];
					}
			}
		} cout<<"\nSuma de elementos entre 5 y 10: "<<suma5a10;
		}
		void printMatriz(){	 
		cout<<"\nMatriz \n";
			for (int i=0; i<size; i++){
				cout<<"\t"<<"[";
				for(int j = 0; j<size; j++){
					cout<<mat[i][j] <<"\t";
				}
				cout<<"]\n";
			}
		}			
		
};
int main(void){
	cout<<"Suma de diagonales y triangulares de matrices\n";

	Matriz<float> m2; m2.setsize(3);
	m2.setMatriz();
	m2.setCell(1,1,4.74);
	m2.setCell(1,0,7.74);
	m2.printMatriz();
	m2.sumaDiagonal();
	m2.TinfSuma();
	m2.TsupSuma();
	m2.Cell5a10();
	
	Matriz<float> m1; m1.setsize(3);
	m1.setMatriz();
	m1.setCell(1,1,4);
	m1.setCell(1,0,7);
	m1.printMatriz();
	m1.sumaDiagonal();
	m1.TinfSuma();
	m1.TsupSuma();
	m1.Cell5a10();
	
}

