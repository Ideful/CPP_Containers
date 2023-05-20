#include <iostream>  
  
using namespace std;  

void printArr(int a[], int n) {  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<< " ";  
}  
void swapper(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int a[], int start, int end);


/* function to implement quick sort */  
void quick(int a[], int start, int end){ /* a[] = array to be sorted, start = Starting index, end = Ending index */  
    if (start < end) {  
        int p = partition(a, start, end);  //p is the partitioning index  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  

int partition (int a[], int start, int end) {  
    int pivot = a[end]; // pivot element  
    int i = (start - 1);  
    for (int j = start; j <= end - 1; j++) {  
        if (a[j] < pivot) {  // If current element is smaller than the pivot  
            i++; // increment index of smaller element  
            swapper(&a[i],&a[j]); //
            printArr(a,4);
            cout<<"\n";
        }  
    }  
    swapper(&a[i+1],&a[end]);
    printArr(a,6);
    cout<<"\n\n\n";
    return (i + 1);  
}  





int main()  
{  
    int a[] = { 9,6,7,2 };  
    int n = sizeof(a) / sizeof(a[0]);  
    cout<<"Before sorting array elements are - \n";  
    printArr(a, n);  
    cout<<"\n\n\n";
    quick(a, 0, n - 1);  
    cout<<"\n\nAfter sorting array elements are - \n";    
    printArr(a, n);  
    // cout << a[n];
      
    return 0;  
}  

/*  
g++ qs.cpp -g && ./a.out
*/