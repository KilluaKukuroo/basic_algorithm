#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cstring>
using namespace std;

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void print_arr(const int a[], int len) {
    for(int i = 0; i < len; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;
}

void generate_random_arr(int a[], int len) {
    for(int i = 0; i<len; i++) {
        a[i] = rand();
    }
}

//judge whether the sorting algorithm works fine
int judge_order(int a[], int len) {
    for(int i=0; i<len; i++) {
        if(a[i] > a[i+1]) {
            cout << "ERROR! The sorted array is not in order from smallest to biggest." << endl;
            return -1;
        }
    }
    return 1;
}

//a1 < a2 < ... <an
void bubble_sort(int a[], int len) {
    for(int i=0; i<len; i++) {
        for(int j=i+1; j<len; j++) {
            if(a[i] > a[j]) swap(a, i, j);
        }
    }
}

void bubble_sort_2(int a[], int len) {
    for(int i=(len-1); i >=0; i--) {
        for(int j=i-1; j>=0; j--) {
            if(a[i] < a[j]) 
                swap(a, i, j);
        }
    }
}

void bubble_sort_3(int a[], int len) {
    int max = -1000;
    int maxindex;
    for(int i=(len-1); i>=0; i--) {
        for(int j=i; j>=0; j--) {
            if(a[j] > max) {
                maxindex = j;
                max = a[j];
            }
        }
        swap(a, i, maxindex);
        max = -1000;
    }
}


/*
quicksort
*/
int partition(int a[], int left, int right) {
    int pivot = left;
    while (left < right)
    {
        while(a[pivot]<=a[right] and right>left) --right;
        while(a[pivot]>=a[left] and right > left) ++left;
        swap(a, left, right);
    }
    swap(a, left, pivot);
    return left;
}

void quicksort(int a[], int left, int right) {
    if(left < right) {
        int pivot = partition(a, left, right);
        quicksort(a, left, pivot-1);
        quicksort(a, pivot+1, right);
    }
}

/**
 * merge sort
*/

void merge(int a[], int left, int mid, int right) {
    int i = left, j = mid+1;
    int k = 0, len = (right-left)+1;
    int * temp = new int[right-left+1];
    while(i <= left and j <= right) {
        if(a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i<=left) 
        temp[k++] = a[i++];
    while(j<=right) 
        temp[k++] = a[j++];
    for(int w=0,p=left; w<len and p<=right; w++,p++) {
        a[p] = temp[w];
    }
    delete [] temp;
}

void devide(int a[], int low, int high) {
    if(low >= high) 
        return;
    int mid = (high-low)/2+low;
    devide(a, low, mid);
    devide(a, mid+1, high);
    merge(a, low, mid, high);
}

int main() {
    //int a[] = {3,1,2, 45,3,42,21};
    int len = 1000;
    int a[len];

    //int len = sizeof(a) / sizeof(a[0]);
    
    
    //randomly generate an array
    generate_random_arr(a, len);
    
    
    int b[len];
    memcpy(b, a, sizeof(a));

    cout << "original array : " << endl;
    print_arr(a, len);

    
    cout << "after bubble sort array : " << endl;
    clock_t begin = clock();
    bubble_sort(a, len);
    clock_t end = clock();
    //bubble_sort_2(a, len);
    //bubble_sort_3(a, len);
    print_arr(a, len);

    double seconds = static_cast<double> (end - begin) / CLOCKS_PER_SEC;
    cout << "bubble sort uses time : " << seconds << " s" << endl;

    judge_order(a, len);

    // int b[len];
    // generate_random_arr(b, len);
    cout << "after quicksort array : " << endl;
    clock_t begin2 = clock();
    quicksort(b, 0, len-1);
    clock_t end2 = clock();
    
    print_arr(b, len);
    seconds = static_cast<double>(end2-begin2) / CLOCKS_PER_SEC;
    cout << "quick sort uses time : " << seconds << " s" << endl;
    return 0;
}