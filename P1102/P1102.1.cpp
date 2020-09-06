//https://www.luogu.com.cn/problem/P1102
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 2e5+4;
int arr[MAXN];

///< 使用map，算法复杂度也是O(nlogn)
int main() {
    int n,c;
    cin>>n>>c;
    map<int, int> mymap;
    for (int i=1; i<=n; i++) {
        cin>>arr[i];
        mymap[arr[i]]++;
    }

    sort(arr+1, arr+n+1);///< 排序
    n = unique(arr+1, arr+n+1)-arr-1;//去重

    //统计数据
    long long ans=0;
    for (int i=1; i<=n; i++) {
        ///< 不论是将 arr[i] 看成 A 或 B，结果是一样的
        int x = arr[i]-c;
        ans += ((long long)mymap[arr[i]]*mymap[x]);        
    }

    cout<<ans<<"\n";
    
    return 0;
}