//https://www.luogu.com.cn/problem/P1271
//P1271 【深基9.例1】选举学生会
#include <bits/stdc++.h>

using namespace std;

const int MAXM=2e6+4;
int sz[MAXM];

int main() {
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++) {
        cin>>sz[i];
    }

    sort(sz+1, sz+m+1);

    for (int i=1; i<=m; i++) {
        cout<<sz[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}