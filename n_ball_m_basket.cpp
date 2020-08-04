#include<iostream>
using namespace std;



//referene : https://www.luogu.com.cn/blog/chengni5673/dang-xiao-qiu-yu-shang-he-zi
int nm_count_1(int n, int m) {
    int count = 0;

    int f[n+1][m+1];
    for(int i=0; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(j == 1 || i == 0) f[i][j] = 1;
            else if(i < j) f[i][j] = f[i][i];
            else if(i >= j) f[i][j] = f[i-j][j] + f[i][j-1];
        }
    }

    printf("%d\n", f[n][m]);
    return count;
}

//reference: https://www.cnblogs.com/huangshiyu13/p/6128036.html
int f(int n, int m) {
    if(n == 0 || m == 1) return 1;
    if(n < m) return f(0,n) + f(n, n-1);
    else return f(n-m,m) + f(n,m-1);
}

int nm_count_2(int n, int m) {
    int count = f(n,m);
    cout << count << endl; 
    return count;
}





int main() {
    int n, m;
    cout << "please input n and m: " << endl;
    //cin >> n >> m;
    n = 7, m = 3;
    //球相同，盒子相同，允许有空盒；
    nm_count_1(n, m);
    nm_count_2(n, m);
    return 0;
}
