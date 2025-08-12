#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int SIZE = 5;

// function prototypes
template <class T>
void printArray(T ar[], int sz);
template <class T>
void selectionSort(T ar[], int sz);

int main()
{
    string sa[SIZE] = {"beta","gamma","alpha","epsilon","delta"};
        // test a
    cout << "Unsorted a:" << endl;
    printArray(sa, SIZE);

    selectionSort(sa,SIZE);

    cout << "Sorted a:" << endl;
    printArray(sa, SIZE);

    cin.get();
    return EXIT_SUCCESS;
}

//----------------------------------------------------------------------------
// prints a of size size
//----------------------------------------------------------------------------
template <class T>
void printArray(T a[], int size)
{
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

//----------------------------------------------------------------------------
// sorts a of size size by selection method
//----------------------------------------------------------------------------
template <class T>
void selectionSort(T a[], int size)
{
    int start = 0;
    for(int i = 0; i < size; i++)
    {
        start = i; // set first element as smallest
        for(int j = i + 1; j < size; j++) // find smallest
            if(a[j] < a[start])
                start = j;
        if(start != i)
            swap(a[start], a[i]);
    } // end for(i)     
}



