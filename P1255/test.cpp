#include <bits/stdc++.h>
using namespace std;

const int MAXN=5002;
unsigned long long ans[MAXN];

int main() {
    int n;
    cin>>n;

    ans[1]=1;
    ans[2]=2;
    for (int i=3; i<=n; i++) {
        ans[i]=ans[i-1]+ans[i-2];
    }

    cout<<ans[n]<<"\n";
    
    return 0;
}