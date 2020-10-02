//https://www.luogu.com.cn/problem/P2392
//P2392 kkksc03考前临时抱佛脚

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = 4;
const int MAXM = 62;
const int MAXT = 2;

int subjects[MAXN];//科目
int times[MAXN][MAXM];//时间
bool used[MAXN][MAXM];//是否复习完成
int Left;//左脑
int Right;//右脑
int minn;//某一门科目最小时间

//从第i门的第j题目开始复习
void dfs(int i, int j) {
    //判断本次搜索是否结束
    if (j>=subjects[i]) {
        minn = min(minn, max(Left, Right));
        return;
    }

    //左脑工作
    Left += times[i][j];
    dfs(i, j+1);
    Left -= times[i][j];

    //右脑工作
    Right += times[i][j];
    dfs(i, j+1);
    Right -= times[i][j];
}

int main() {
    for (int i=0; i<4; i++) {
        cin >> subjects[i];
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<subjects[i]; j++) {
            cin >> times[i][j];
        }
    }

    //搜索
    int ans = 0;//最后的时间
    for (int i=0; i<4; i++) {
        Left=0;//左脑清零
        Right=0;//右脑清零
        minn = INT_MAX;//由于是要最小值
        dfs(i, 0);//从第i门的第一题开始复习
        ans += minn;
    }

    cout << ans << endl;

    return 0;
}