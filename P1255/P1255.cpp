///> https://www.luogu.com.cn/problem/P1255
///> 递推+高精度
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN=5e3+4;
int ans[MAXN][MAXN];

///> 高精度加法
void BigNumAdd(int a[], int b[], int c[]) {
    int len=max(a[0], b[0]);
    c[0]=len;

    int jw=0;
    for (int i=1; i<=len; i++) {
        c[i]=a[i]+b[i]+jw;
        jw=c[i]/10;
        c[i]%=10;
    }
    if (0!=jw) {
        c[len+1]=jw;
        c[0]++;
    }
}

int main() {
    int n;
    cin>>n;

    ///< 一个台阶的走法
    ans[0][0]=1;
    ans[0][1]=0;
    ///< 一个台阶的走法
    ans[1][0]=1;
    ans[1][1]=1;
    ///< 两个台阶的走法
    ans[2][0]=1;
    ans[2][1]=2;

    for (int i=3; i<=n; i++) {
        BigNumAdd(ans[i-1], ans[i-2], ans[i]);
    }

    ///< 输出
    //for (int j=1; j<=n; j++) {
        for (int i=ans[n][0]; i>0; i--) {
            cout<<ans[n][i];
        }
        cout<<"\n";
    //}

    return 0;
}