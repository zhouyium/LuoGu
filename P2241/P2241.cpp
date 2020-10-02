//https://www.luogu.com.cn/problem/P2241
//P2241 统计方形（数据加强版）

/*
排列组合问题
n*m 的棋盘
所有矩形 = 正方形个数 + 长方形个数
所有矩形 = C(2, n+1)*C(2, m+1) = ((n+1)*n/2)*((m+1)*m/2)
再暴力枚举出所有的正方形
假设 f(i) 为边长是 i 的正方形个数，可以得到 (n-i+1)*(m-1+1) 个。
====
数据范围估计
(n+1)*n/2=5000*5001/2=12.6e6=1.26e7
(m+1)*m/2=5000*5001/2=12.6e6=1.26e7
总数为 1.26e7*1.26e7=1.26e14
需要使用 long long
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin>>n>>m;
    
    long long x=((n+1)*n/2)*((m+1)*m/2);//矩形总数
    //暴力枚举正方形个数
    long long y=0;//正方形个数
    for (long long i=1; i<=min(m, n); i++) {
        y += (n-i+1)*(m-i+1);
    }

    cout<<y<<" "<<x-y<<"\n";

    return 0;
}