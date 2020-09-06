//< https://www.luogu.com.cn/problem/P1706
//< 全排列问题
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<int> ans;
bool vis[10];

void dfs(int step) {
    if (step>=n) {
        for (int i=0; i<n; i++) {
            printf("%5d", ans[i]);
        }
        printf("\n");
        return;
    }

    for (int i=1; i<=n; i++) {
        if (false==vis[i]) {
            vis[i]=true;
            ans.push_back(i);
            dfs(step+1);
            ans.pop_back();
            vis[i]=false;
        }
    }
}

int main() {
    cin>>n;
    dfs(0);
    return 0;
}