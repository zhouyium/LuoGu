//https://www.luogu.com.cn/problem/P1157
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 2e1+4;
bool vis[MAXN];///< 可见性控制
vector<int> ans;///< 结果

int n, r;

void dfs(int step, int idx) {
    ///< 出口
    if (step>=r) {
        for (int i=0; i<r; i++) {
            printf("%3d", ans[i]);
        }
        cout<<"\n";
        return;
    }

    for (int i=idx+1; i<=n; i++) {
        if (false==vis[i]) {
            vis[i]=true;
            ans.push_back(i);
            dfs(step+1, i);
            ans.pop_back();
            vis[i]=false;
        }
    }
}

int main() {
    cin>>n>>r;

    dfs(0, 0);

    return 0;
}