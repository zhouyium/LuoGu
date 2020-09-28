//https://www.luogu.com.cn/problem/P2078
//P2078 朋友
//使用 STL Map 实现
#include <bits/stdc++.h>

using namespace std;

map<int, int> ds;//并查集
map<int, int> ranks;

//查找x的父亲
int find_root(int x) {
    return x==ds[x]?x:ds[x]=find_root(ds[x]);
}

//建立关系
void union_set(int x, int y) {
    int x_root=find_root(x);
    int y_root=find_root(y);
    if (x_root!=y_root) {
        if (ranks[x_root]>ranks[y_root]) {
            ds[y_root]=x_root;
        } else if (ranks[x_root]<ranks[y_root]) {
            ds[x_root]=y_root;
        } else {
            ds[x_root]=y_root;
            ranks[y_root]++;
        }
    }
}

//查找x和y是否在同一个父亲
bool relation(int x, int y) {
    return find_root(x)==find_root(y);
}

int main() {
    int n,m,p,q;
    cin>>n>>m>>p>>q;

    //初始化并查集
    for (int i=-1*m; i<=n; i++) {
        ds[i]=i;//将父亲设置为自己
        ranks[i]=0;
    }

    //读入关系
    for (int i=1; i<=p+q; i++) {
        int x,y;
        cin>>x>>y;
        union_set(x, y);
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