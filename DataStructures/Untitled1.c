#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
   int arr[10000],i,j,min,temp;
   for(i=0;i<10000;i++){
      arr[i]=rand()%10000;
   }
   //bubble Sort
   clock_t start,end;
   start=clock();
   for(i=0;i<10000;i++)
   {
     for(j=i+1;j<10000;j++)
     {
       if(arr[i]>arr[j])
       {
         int temp=arr[i];
         arr[i]=arr[j];
         arr[j]=temp;
       }
     }
   }
   end=clock();
   double extime=(double) (end-start)/CLOCKS_PER_SEC;
   printf("\n\tBubble Sort:  %f segs\n ",extime);

   for(i=0;i<10000;i++)
   {
     arr[i]=rand()%10000;
   }
   clock_t start1,end1;
   start1=clock();
   // Selection Sort
   for(i=0;i<10000;i++)
   {
     min=i;
     for(j=i+1;j<10000;j++)
     {
       if(arr[min]>arr[j])
       {
         min=j;
       }
     }
     temp=arr[min];
     arr[min]=arr[i];
     arr[i]=temp;
   }
   end1=clock();
   double extime1=(double) (end1-start1)/CLOCKS_PER_SEC;
   printf("\tSelection sort:  %f segs\n\n", extime1);
   
   
   
   //Quick Sort
   clock_t start4,end4;
   start4=clock();
	void swap(int *a, int *b){
	  int t=*a;
	  *a=*b;
	  *b=t;
	}
	int partition(int arr[], int l, int h){
		int pivot=arr[h];
		int i=(l-1);
		int j; 
		for (j=l; j<h; j++){
		    if (arr[j]<=pivot){
		      i++;
		      swap(&arr[i], &arr[j]);
		    }
	  }
	  swap(&arr[i+1], &arr[h]);
	  return (i+1);
	}
   void quick_sort(int arr[], int l, int h){
  	if (l<h){
    int pi=partition(arr, l, h);
    quick_sort(arr, l, pi-1);
    quick_sort(arr, pi + 1, h);
  	}
	}
  	quick_sort(arr, 0,1499);
  	end4=clock();
   double extime4=(double) (end4-start4)/CLOCKS_PER_SEC;
   printf("\tQuick sort:  %f segs\n\n", extime4);

}


