#include <iostream>

using namespace std;

void swapper(int *a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printer(int a[], int n, int pivot) {
        cout<<"\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout<<"| " << pivot;
}

int partition(int a[], int start, int end, int size) {
    int pivot = a [end];
    int i = start - 1;
    for(int j = start; j <= end; j++) {
        if (a[j] < pivot) {
            i++;
            swapper(&a[i],&a[j]);
            printer(a,size, pivot);
        }
    }
    swapper(&a[i+1],&a[end]);
    printer(a,size, pivot);
    // cout<<"\n\n";
    return i+1;
}

void qs(int a[], int start, int end, int size) {
    if (start < end) {
        int pivot = partition(a,start,end,size);
        cout << " | " << pivot << "<-pivot index \n\n";
        qs(a, start, pivot-1,size);
        qs(a, pivot + 1, end,size);
    }
}

int main() {
    int a[] = {8,7,6,5,2,3,1,9,4};
    int size = sizeof(a)/sizeof(a[0]);
    printer(a,size, 0);
    cout<<"\n\n";
    qs(a,0,size-1,size);
    printer(a,size, 0);
}