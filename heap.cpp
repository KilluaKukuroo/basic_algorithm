#include<iostream>
using namespace std;

void printarr(int a[], int len) {
    for(int i=0; i<len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void createMaxHeap(int a[], int index) {
    //int index = len/2 - 1;

    for(int i=index; i>=0; i--) {
        if(a[index] < a[2*index+1]) swap(a, index, 2*index+1);
        if(a[index] < a[2*index+2]) swap(a, index, 2*index+2);
        index = index - 1;
    }
}


void adjustheap(int a[], int len, int k) {
    int temp = a[k];
    for(int i=2*k+1; i<len; i=2*k+1) {
        if(i+1<len and a[i] < a[i+1]) 
            i++;
        if(a[i] > a[k]) {
            a[k] = a[i];
            k = i;
        }
        
    }
    a[k] = temp;
}

void heapsort(int a[], int len) {
    //1.consteruct max heap
    for(int i=len/2-1; i>=0; i--) {
        adjustheap(a, len, i);
    }
}


int main() {
    int a[] = {1,2,3,4,5,6,7};
    int len = sizeof(a) / sizeof(a[0]);
    int index = len/2 - 1;
    createMaxHeap(a, index);
    printarr(a, len);
    return 0;
}