//https://www.luogu.com.cn/problem/P3367
//【模板】并查集

#include <bits/stdc++.h>

using namespace std;

//并查集
typedef struct _DISJOINTSET {
    static const int MAXN=1e4+4;
    int n;//数据量
    int parent[MAXN];//父节点
    int rank[MAXN];//层数

    _DISJOINTSET() {
        init(MAXN);
    }

    //初始化数据
    void init(int size=MAXN) {
        memset(parent, -1, size*sizeof(int));
        memset(rank, 0, size*sizeof(int));
    }

    //查找节点 x 的父节点
    int find_root(int x) {
        int x_root=x;
        while (-1 != parent[x_root]) {
            x_root=parent[x_root];
        }
        return x_root;
    }

    //将节点 x 和节点 y 合并
    int union_set(int x, int y) {
        int x_root=find_root(x);
        int y_root=find_root(y);

        if (x_root==y_root) {
            //不需要合并
            return 0;
        } else {
            if (rank[x_root]>rank[y_root]) {
                parent[y_root]=x_root;
            } else if (rank[x_root]<rank[y_root]) {
                parent[x_root]=y_root;
            } else {
                parent[x_root]=y_root;
                rank[y_root]++;
            }
            return 1;
        }
    }
} DISJOINTSET;

int main() {
    int n,m;
    cin>>n>>m;

    DISJOINTSET myDS;

    for (int i=0; i<m; i++) {
        int op,x,y;
        cin>>op>>x>>y;

        if (1==op) {
            //合并
            myDS.union_set(x, y);
        } else if (2==op) {
            //查询
            int x_root=myDS.find_root(x);
            int y_root=myDS.find_root(y);
            if (x_root==y_root) {
                cout<<"Y\n";
            } else {
                cout<<"N\n";
            }
        }
    }

    return 0;
}