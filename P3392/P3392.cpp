//https://www.luogu.com.cn/problem/P3392
//P3392 涂国旗
/*
由于数据量小，N,M≤50。
可以直接用暴力
 */ 
#include <bits/stdc++.h>

using namespace std;

const int MAXN=50+4;
char arr[MAXN][MAXN];

int main() {
    int n,m;
    cin>>n>>m;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin>>arr[i][j];
        }
    }

    /*
    第 1 行到第 i 行是白色；i的范围就是 1 ~ n-2
    第 i+1 行到第 j 行是蓝色；
    第 j+1 行到第 n 行是红色。
    */
    int ans=MAXN*MAXN;
    for (int i=1; i<=n-2; i++) {
        for (int j=i+1; j<=n; j++) {
            int tot=0;

            //涂白色
            for (int k=1; k<=i; k++) {
                for (int l=1; l<=m; l++) {
                    if ('W'!=arr[k][l]) {
                        tot++;
                    }
                }
            }
            //涂蓝色
            for (int k=i+1; k<=j; k++) {
                for (int l=1; l<=m; l++) {
                    if ('B'!=arr[k][l]) {
                        tot++;
                    }
                }
            }
            //涂红色
            for (int k=j+1; k<=n; k++) {
                for (int l=1; l<=m; l++) {
                    if ('R'!=arr[k][l]) {
                        tot++;
                    }
                }
            }

            ans=min(ans, tot);
        }
    }

    cout<<ans<<"\n";

    return 0;
}