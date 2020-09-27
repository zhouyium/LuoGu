//https://www.luogu.com.cn/problem/P1551
//P1551 亲戚
//并查集
#include <bits/stdc++.h>

using namespace std;

typedef struct _DISJOINTSET {
    static const int MAXN=5e3+4;
    int parent[MAXN]={};//记录父节点
    int rank[MAXN]={};//记录层数

    _DISJOINTSET() {
        init();
    }

    void init(int size=MAXN) {
        memset(parent, -1, sizeof(parent));
        memset(rank, 0, sizeof(rank));
    }

    //查集
    int find_root(int x) {
        int x_root=x;
        while (-1!=parent[x_root]) {
            x_root=parent[x_root];
        }
        return x_root;
    }

    //并集
    int union_set(int x, int y) {
        int x_root=find_root(x);
        int y_root=find_root(y);

        if (x_root==y_root) {
            //已经是一个集合，没有必要并
            return 0;
        } else {
            if (rank[x_root]>rank[y_root]) {
                parent[y_root]=x_root;
            } else if (rank[x_root]<rank[y_root]) {
                parent[x_root]=y_root;
            } else {
                //相等
                parent[x_root]=y_root;
                rank[y_root]++;
            }
        }
    }
} DISJOINSET;

int main() {
    int n,m,p;
    cin>>n>>m>>p;

    DISJOINSET ds;
    for (int i=1; i<=m; i++) {
        int x,y;
        cin>>x>>y;
        ds.union_set(x, y);
    }
    for (int i=1; i<=p; i++) {
        int x,y;
        cin>>x>>y;
        
        int x_root = ds.find_root(x);
        int y_root = ds.find_root(y);
        if (x_root==y_root) {
            cout<<"Yes\n";
        } else {
            cout<<"No\n";
        }
    }
    
    return 0;
}