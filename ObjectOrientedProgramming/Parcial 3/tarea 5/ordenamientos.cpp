#include<iostream>
#include<vector>
using namespace std;

template<class T>
class ordenamiento{
	private: int i,j,k, size; T temp;
	public:	
		T bubbleSort(T a[], int n){
			size=n;
			for(int i=0; i<size; i++){
				for(j=i+1; j<size; j++){
					if(a[i]>a[j]){
						temp=a[i];
						a[i]=a[j];
						a[j]=temp;}
					}
				}
			}
		
		void setelement(T a[],int pos, T value){
			a[pos]=value; 
		}
		T getelement(T a[], int pos){
			return a[pos];
		}
		void merge(T a[], int start, int end){
		    int z, x, y, half;
		    vector<T> temp(end-start+1);
		    half=(start+end)/2;
		    z=0; x=start; y=half+1;
		    while (x<=half && y<=end){
		        if (a[x]<a[y]){
		            temp[z]=a[x];
		            x++; z++;}
		        else{
		            temp[z]=a[y];
		            y++; z++;}
		    }
		    while (x<=half){
		        temp[z]=a[x];
		        x++; z++;
		    }	
		    while (y<=end){
		        temp[z]=a[y];
		        y++;z++;
		    }
		    for (int i=start; i<=end; i++){
		        a[i]=temp[i-start];
		    }
		}
		T mergeSort(T a[], int start, int end){
			    if (start<end){
			        int half=(start+end)/2;
			        mergeSort(a, start, half); 
			        mergeSort(a, half + 1, end); 
			        merge(a, start, end); }
			}
		void print(T a[], int n){
				cout<<"\n";
				for (int i = 0; i < n; i++)
					cout << a[i] << " ";
		}
		T selectionSort(T a[], int size){
		    int  x=0;
		    for(int i= 0; i< size; i++){ x=i; 
		        for(j= i+1; j<size;j++) {
		        if(a[j] < a[x])
		            x=j;}
		        if(x != i){
		            temp= a[x];
		            a[x]=a[i];
		            a[i]=temp;
		    	}
		    }    
		}
		int partition(T a[], int start, int n){
			j=start; int piv=n;
			for(int i=start;i<n;i++){
				if(a[i]<a[piv]){
					swap(a[i],a[j]);
					++j;
				}
			}
			temp=a[j]; a[j]=a[piv]; a[piv]=temp;
			return j;
			
		}
		T quickSort(T a[], int start, int end ){
		
			if(start<end){
				int p = partition(a,start,end);
				quickSort(a,start,p-1);
				quickSort(a,p+1,end);
			}
			
		}

};

int main(){
	
	cout<<"ORDENAMIENTOS: \n";
 
    ordenamiento<int> o1;
	int arr1[]={1,45,12,5,3};
	o1.bubbleSort(arr1,5); o1.print(arr1,5);
	
	ordenamiento<double>o2;
	double arr2[]={ 3.0, 3.2, 2.99,2.998, 2.909,2.009 };
	o2.mergeSort(arr2, 0, 5); o2.print(arr2,6);
	//value set
	o2.setelement(arr2,3,2.1);
	//reorder
	o2.mergeSort(arr2, 0, 5); o2.print(arr2,6);
	
	ordenamiento<char>o3;
	char arr3[]={'d','i','a','n','a'};
	o3.selectionSort(arr3,5); o3.print(arr3,5);
	
	ordenamiento<float>o4;
	float arr4[]={12.23,32.12,12.32,31.22,22.13,22.31};
	o4.quickSort(arr4, 0, 5); o4.print(arr4,6);
  

}

