#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

template<typename T,int size>
class calculadoraMatrices{
	private:
	    T mat[size][size];
	public:
	    calculadoraMatrices(){
	        for(int i=0;i<size;i++){
	            for(int j=0;j<size;j++){
	                 setMatriz(i,j,0);
					}
	        }
	    }
		void setMatriz(int i,int j,T mat){
			this->mat[i][j]=mat;
		}
	    T getvalues(int i,int j){
			return this->mat[i][j];
		}
		void values(){
	        for(int i=0;i<size;i++){
	            for(int j=0;j<size;j++){
	                setMatriz(i,j,(T)(rand()%10));
	            }
	        }
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
		calculadoraMatrices operator+(calculadoraMatrices &amo){
		calculadoraMatrices val;
		for (int i=0;i<size;i++){
			for (int j= 0;j<size;j++){
				val.mat[i][j]=this->getvalues(i,j)+amo.getvalues(i,j);
			}
		}
		return(val);
	    }
	    calculadoraMatrices operator-(calculadoraMatrices &amo){
		calculadoraMatrices val;
		for (int i=0;i<size;i++){
			for (int j= 0;j<size;j++){	
				val.mat[i][j] = this->getvalues(i,j)- amo.getvalues(i,j);
			}
			}
		return(val);
	    }
		
	    calculadoraMatrices operator*(calculadoraMatrices &amo){
		calculadoraMatrices val;
		for (int i=0;i<size;i++){
			for (int j= 0;j<size;j++)
	        {   for(int z=0; z<size; z++)
				val.mat[i][j] += this->getvalues(i,z)*amo.getvalues(z,j);
			}
		}
		return(val);
	    }

};
int main(){
    calculadoraMatrices<int,3> m1,m2,m3;
    cout<<"A\n";
    m1.values();
    m1.printMatriz();
    cout<<"B\n";
    m2.printMatriz();
    m2.values();
    cout<<"Suma \n";
    m3=m1+m2;
	m3.printMatriz();
	cout<<"Resta \n";
    m3=m1-m2;
	m3.printMatriz();
	cout<<"Multiplicacion \n";
    m3=m1*m2;
	m3.printMatriz();

}
