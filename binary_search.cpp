#include<iostream>
#include<cmath>
using namespace std;


//judge whether the array is sorted from smallest to largest
int judge_order(int a[], int len) {
    for(int i=0; i<len-1; i++) {
        if(a[i] > a[i+1]) {
            cout << "judge_order: not in order, please sort it first." << endl;
            return -1;
        }
    }
    return 0;
}

int partition(int a[], int left, int right) {
    int pivot = left;
    while(left < right) {
        while(a[right] >= a[pivot] and (right>left)) right--;
        while(a[left] <= a[pivot] and left<right) left++;
        int temp = a[right];
        a[right] = a[left];
        a[left] = temp;
    }
    int temp = a[pivot];
    a[pivot] = a[left];
    a[left] = temp;
    return left;
}

void quicksort(int a[], int left, int right) {
    if(left < right) {
        int pivot = partition(a, left, right);
        quicksort(a, left, pivot-1);
        quicksort(a, pivot+1, right);
    }

    //return 0;
}

//non-recursive version
int binary_search(int a[], int len, int value) {
    int left = 0;
    int right = len - 1;
    int middle = (right-left) / 2;
    while(left <= right) {
        middle = (right-left) / 2 + left;
        if(value > a[middle]) left = middle + 1;
        else if (value < a[middle]) right = middle - 1;
        else return middle;   //return the index of value in a 
    }
    return -1; //didn't find value in a
}

//recursive version
int binary_search_recursive(int a[], int left, int right,  int value) {
    if(left > right) return -1;
    int middle = (right - left) / 2 + left;
    if(value > a[middle]) binary_search_recursive(a, middle+1, right, value);
    else if(value < a[middle]) binary_search_recursive(a, left, middle-1, value);
    else return middle;
}

//suppose A is in decending order
int one_third_search(int A[], int Z, int left, int right) {
    int n = right - left;
    //cout << "left, right == " << left << " " << right;
    if(n < 0) return -1;
    if(A[n/3+left] == Z) return n/3+left;
    if(A[2*n/3 + left] == Z) return 2*n/3+left;
    if(A[n/3+left] < Z) one_third_search(A,Z,left,n/3+left-1);
    else if(A[2*n/3+left] < Z) one_third_search(A, Z, n/3+left+1, 2*n/3+left-1);
    else one_third_search(A, Z, 2*n/3+left+1, right);
}

void printarr(int a[], int len) {
    for(int i=0; i<len; i++) {
        cout << a[i] << " " ;
    }
    cout << endl;
} 

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition2(int a[], int left, int right) {
    int pivot = left;
    while(left < right) {
        while(a[right] >= a[pivot] and (left<right)) right--;
        while(a[left] <= a[pivot] and (left<right)) left++;
        swap(a, left, right);
    }
    swap(a, pivot, left);
}
void quicksort2(int a[], int left, int right) {
    if(left < right) {
        int pivot = partition(a, left, right);
        quicksort(a, left, pivot-1);
        quicksort(a, pivot+1, right);
    }
}

int main() {
    int a[] = {1,4,2,56,34,23,10,5};
    
    //int a[] = {1,2,3,4,10,20};
    int len = sizeof(a) / sizeof(a[0]);
    printarr(a, len);
    if(judge_order(a, len) == -1)
        quicksort2(a, 0, len-1);
    printarr(a, len);
    int value = 10;
   
    int result = binary_search(a, len, value);
    cout << "binary_search : the index of value is : " << result << endl;
    int result2 = binary_search_recursive(a, 0, len-1, value);
    cout << "binary_search_recursive : the index of value is : " << result2 << endl;
    
    int b[] = {34,23,12,10,9,8,7,6,5,4,3,2,1};
    int result3 = one_third_search(b, 61, 0, sizeof(b) / sizeof(b[0]));
    cout << "one third search : the index of the value is : " << result3 << endl;


    return 0;
}