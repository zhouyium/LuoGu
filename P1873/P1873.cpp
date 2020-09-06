//https://www.luogu.com.cn/problem/P1873
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=1e6+4;
int arr[MAXN];
long long n, m;

/**
 * 以 mid 对所有树木进行分割，看能否达到要求
 */
bool check(long long mid) {
    long long ans=0;
    for (int i=1; i<=n; i++) {
        if (arr[i]>mid) {
            ans += (arr[i]-mid);
            if (ans>=m) {
                return true;///< 可以分割
            }
        }        
    }
    return false;///< 不能分割
}

long long bSearch(long long l, long long r) {
    long long mid;
    while (l<r) {
        mid=l+((r-l+1)>>1);
        if (check(mid)) {
            ///< 将mid变大
            l=mid;
        } else {
            ///< 将mid变小
            r=mid-1;
        }
    }
    return l;
}

int main() {
    long long r=0;

    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        cin>>arr[i];
        if (arr[i]>r) {
            r=arr[i];
        }
    }

    long long l=1;
    cout<<bSearch(l, r)<<"\n";

    return 0;
}