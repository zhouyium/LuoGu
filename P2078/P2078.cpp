//https://www.luogu.com.cn/problem/P2078
//P2078 朋友
#include <bits/stdc++.h>

using namespace std;

typedef struct _DISJOINTSET {
    static const int MAXN=1e4+4;
    int parent[MAXN];
    int rank[MAXN];

    _DISJOINTSET(int size=MAXN) {
        init(size);
    }

    void init(int size=MAXN) {
        memset(parent, -1, size*sizeof(int));
        memset(rank, 0, size*sizeof(int));
    }

    int find_root(int x) {
        int x_root=x;
        while (-1!=parent[x_root]) {
            x_root=parent[x_root];
        }
        return x_root;
    }

    void union_set(int x, int y) {
        bool flag=false;
        int x_root=find_root(x);
        int y_root=find_root(y);

        if (x_root!=y_root) {
            if (rank[x_root]>rank[y_root]) {
                parent[y_root]=x_root;
            } else if (rank[x_root]<rank[y_root]) {
                parent[x_root]=y_root;
            } else {
                parent[x_root]=y_root;
                rank[y_root]++;
            }
        }
        return;
    }
} DISJOINTSET;

int main() {
    int n,m,p,q;
    cin>>n>>m>>p>>q;

    DISJOINTSET man;
    DISJOINTSET woman;

    //建立男人的集合
    for (int i=1; i<=p; i++) {
        int x,y;
        cin>>x>>y;
        man.union_set(x, y);
    }

    //建立女人的集合
    for (int i=1; i<=q; i++) {
        int x,y;
        cin>>x>>y;
        woman.union_set(abs(x), abs(y));
    }

    //找到认识小明的男人有几个，包括小明。
    int man_root=man.find_root(1);
    int boys=0;
    for (int i=1; i<=n; i++) {
        if (man_root==man.find_root(i)) {
            boys++;
        }
    }

    //找到认识小红的女生有几个，包括小红。
    int woman_root=woman.find_root(1);
    int girls=0;
    for (int i=1; i<=m; i++) {
        if (woman_root==woman.find_root(i)) {
            girls++;
        }
    }

    cout<<min(boys, girls)<<"\n";

    return 0;
}