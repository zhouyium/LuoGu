//https://www.luogu.com.cn/problem/P1536
//P1536 村村通
#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e3+4;
map<int, int> ds;
map<int, int> ranks;

int find_root(int x) {
    return x==ds[x] ? x : ds[x]=find_root(ds[x]);
}

void union_set(int x, int y) {
    int x_root=find_root(x);
    int y_root=find_root(y);

    if (x_root!=y_root) {
        if (ranks[x_root]>ranks[y_root]) {
            ds[y_root]=x_root;
        } else if (ranks[x_root]<ranks[y_root]) {
            ds[x_root]=y_root; 
        } else {
            ds[y_root]=x_root;
            ranks[x_root]++;
        }
    }
}

int main() {
    int n,m;
    while (cin>> n) {
        if (0==n) {
            break;
        }
        cin>>m;

        //初始化并查集
        for (int i=1; i<=n; i++) {
            ds[i]=i;
            ranks[i]=0;
        }

        //并集
        for (int i=1; i<=m; i++) {
            int x,y;
            cin>>x>>y;
            union_set(x, y);
        }

        //查询集合数量
        int cnt=0;
        for (int i=1; i<=n; i++) {
            if (ds[i]!=i) {
                cnt++;
            }
        }
        int ans=n-1-cnt;
        if (ans<0) {
            ans=0;
        }
        cout<<ans<<"\n";
    }

    return 0;
}