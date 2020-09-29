//https://www.luogu.com.cn/problem/P2814
//P2814 家谱
#include <bits/stdc++.h>

using namespace std;

const int MAXN=5e4+4;
map<string, string> ds;

string find_root(string x) {
    return x==ds[x] ? x : ds[x]=find_root(ds[x]);
}

void union_set(string x, string y) {
    ds[y]=x;
}

int main() {
    char ch;
    string father;
    string s;

    while (cin>>ch) {
        if ('$'==ch) {
            break;
        }

        cin>>s;
        //初始化
        if (""==ds[s]) {
            ds[s]=s;
        }

        if ('?'==ch) {
            //查询
            string t = find_root(s);
            cout<<s<<" "<<t<<"\n";
        } else if ('#'==ch) {
            father=s;
        } else if ('+'==ch) {
            //建立索引
            union_set(father, s);
        }
    }

    return 0;
}