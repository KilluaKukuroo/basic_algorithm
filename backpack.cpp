
/*
背包问题求解
*/

/*
Fibonacci problem:
    f0 = 1; f1 = 1; fn = f(n-1) + f(n-2)
*/

int fib_recur(int n) {
    if(n == 0 || n == 1) {
        return 1;
    } else {
        return fib_recur(n-1) + fib_recur(n-2);
    }
}


int main() {
    
}