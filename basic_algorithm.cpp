#include<iostream>
#include<math.h>
using namespace std;
#include<string>


//declare functions, after declaration the position where the function is defined does not matter;
void print_array(int a[], int n);
void print_array(float a[], int n);
void exchange_elem(int &a, int &b);

/*
func: bubble sort
*/
int bubble_sort(int a[], int length) {
    cout << "length = " << length << endl;
    for(int i=0; i<length-1; i++) {
        for(int j=0; j<length-1; j++) {
            if(a[j] < a[j+1]) { //exchange two adjacent number
                exchange_elem(a[j], a[j+1]);      
            }
        }
        //print the array
        print_array(a, length);
    }
    /*
    int min = 100000;
    for(int i=0; i<length; i++){
        if(a[i] < min) {
            min = a[i];
        }
    }
    */
    return 0;
}


/*
func：交换两个数组元素， 引用传递
*/
void exchange_elem(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


/*
func: 打印数组
type: int array
*/
void print_array(int a[], int len) {
    for(int i=0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

/*
func: 打印数组, 操作符重载
type: float array
*/
void print_array(float a[], int len) {
    for(int i=0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


/*
func: 快速排序
*/
int quick_sort(int a[]) {

    return 0;
}

/*
func: 查找数组中重复的数字
*/
int find_repeat(int a[]) {

    return 0;
}

/*
func: 堆排序
*/





int main() {
    int a[] = {1,3,3,5,90,34,23,4,2,2,3};
    int length = sizeof(a) / sizeof(a[0]);
    bubble_sort(a, length);
    cout << a << endl;
    cout << "test" << endl;

    exchange_elem(a[0], a[1]);
    print_array(a, length);


    
    char str[] = {'w', 'o', 'r', 'l', 'd', '\0'};
    cout << str << endl;

    char str2[] = "bing";
    cout << str2 << endl;

    string str3[] = {"i", "love", "China"};
    cout << str3 << endl;


    char s[] = "this is a string";
    cout << s << endl;
    s[0] = 'k';
    cout << s << endl;

    char *ss = "bing";
    
    
    

    return 0;
}