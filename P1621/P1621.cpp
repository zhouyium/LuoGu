//https://www.luogu.com.cn/problem/P1621
//P1621 集合
#include <bits/stdc++.h>

using namespace std;

map<int, int> ds;
map<int, int> ranks;
vector<int> primes;

bool isPrime(int x) {
    for (int i=2; i*i<=x; i++) {
        if (0==x%i) {
            return false;
        }
    }
    return true;
}

int find_root(int x) {
    return x==ds[x]?x:ds[x]=find_root(ds[x]);
}

int union_set(int x, int y) {
    int x_root=find_root(x);
    int y_root=find_root(y);
    if (x_root==y_root) {
        return 0;
    } else {
        if (ranks[x_root]>ranks[y_root]) {
            ds[y_root]=x_root;
        } else if (ranks[x_root]<ranks[y_root]) {
            ds[x_root]=y_root;
        } else {
            ds[x_root]=y_root;
            ranks[y_root]++;
        }
        return 1;
    }
}

int main() {
    int a,b,p;
    cin>>a>>b>>p;

    //初始化并查集
    for (int i=a; i<=b; i++) {
        ds[i]=i;
        ranks[i]=0;
    }

    //列出p到b之间的所有素数
    for (int i=p; i<=b; i++) {
        if (true==isPrime(i)) {
            primes.push_back(i);
        }
    }

    //并集
    for (int i=0; i<primes.size(); i++) {
        int st=ceil(1.0*a/primes[i])*primes[i];
        for (int j=st+primes[i]; j<=b; j+=primes[i]) {
            union_set(st, j);
        }
    }

    //查询有几个集合
    int ans=0;
    for (int i=a; i<=b; i++) {
        if (ds[i]==i) {
            ans++;
        }
    }
    cout<<ans<<"\n";

    return 0;
}