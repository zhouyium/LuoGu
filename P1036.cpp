//https://www.luogu.com.cn/problem/P1036
#include <iostream>

using namespace std;

//#define __PRINT

const int MAXN = 2e1+4;
int n, k;
int arr[MAXN];///< @var 数据
bool vis[MAXN];///< @var 可见性
int ans;///< @var 最终答案

/**
 判断素数 
 @param x表示判断的数据
 @return false表示x不是素数，true表示x是素数
 */
bool isPrime(int x) {
    if (x<2) {
        return false;
    }
    for (int i=2; i*i<=x; i++) {
        if (0==x%i) {
            return false;
        }
    }
    return true;
}

/**
 DFS函数
 @param sum 表示当前搜索的总和
 @param step 表示当前搜索的步数
 @param idx 表示数组下标
 */
void dfs(int sum, int step, int idx) {
    ///< 退出条件
    if (step>=k) {
        if (true==isPrime(sum)) {
            ans++;
#if defined(__PRINT)
            for (int i=1; i<=n; i++) {
                if (true==vis[i]) {
                    cout<<i<<" ";
                }
            }
            cout<<"\n";
#endif
        }
        return;
    }

    ///< 开始搜索
    for (int i=idx+1; i<=n; i++) {
        if (false==vis[i]) {
            vis[i]=true;
            dfs(sum+arr[i], step+1, i);
            vis[i]=false;
        }
    }
}

int main() {
    cin>>n>>k;
    for (int i=1; i<=n; i++) {
        cin>>arr[i];
    }

    dfs(0, 0, 0);

    cout<<ans<<"\n";

    return 0;
}