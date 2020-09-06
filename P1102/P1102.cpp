//https://www.luogu.com.cn/problem/P1102
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2e5+4;
int arr[MAXN];

///< 使用二分查找，复杂度为O(nlogn)
int main() {
    int n,c;
    cin>>n>>c;
    for (int i=1; i<=n; i++) {
        cin>>arr[i];
    }

    sort(arr+1, arr+n+1);

    //二分查找
    long long ans=0;
    for (int i=1; i<=n; i++) {
        ///< 不论是将 arr[i] 看成 A 或 B，结果是一样的
        int x = arr[i]-c;
        int pos0 = lower_bound(arr+1, arr+n+1, x)-arr;
        int pos1 = upper_bound(arr+1, arr+n+1, x)-arr;
        ans += (pos1-pos0);
    }

    cout<<ans<<"\n";
    
    return 0;
}