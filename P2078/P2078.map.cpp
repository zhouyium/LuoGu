//https://www.luogu.com.cn/problem/P2078
//P2078 朋友
//使用 STL Map 实现
#include <bits/stdc++.h>

using namespace std;

map<int, int> ds;//并查集

//查找x的父亲
int find(int x) {
    return x==ds[x]?x:ds[x]=find(ds[x]);
}

//建立关系
void judge(int x, int y) {
    ds[find(x)]=find(y);
}

//查找x和y是否在同一个父亲
bool relation(int x, int y) {
    return find(x)==find(y);
}

int main() {
    int n,m,p,q;
    cin>>n>>m>>p>>q;

    //初始化并查集
    for (int i=-1*m; i<=n; i++) {
        ds[i]=i;//将父亲设置为自己
    }

    //读入关系
    for (int i=1; i<=p+q; i++) {
        int x,y;
        cin>>x>>y;
        judge(x, y);
    }

    //查找男生认识小明
    int boys=0;
    for (int i=1; i<=n; i++) {
        if (relation(ds[i], 1)) {
            boys++;
        }
    }

    //查找女生认识小红
    int girls=0;
    for (int i=-1*m; i<=-1; i++) {
        if (relation(ds[i], -1)) {
            girls++;
        }
    }

    cout<<min(boys, girls)<<"\n";

    return 0;
}