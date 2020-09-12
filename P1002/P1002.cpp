//https://www.luogu.com.cn/problem/P1002
#include <bits/stdc++.h>

using namespace std;

const int MAXN=20+8;
long long ans[MAXN][MAXN];

int main() {
    ///< point B coordinate
    int xb,yb;
    cin>>xb>>yb;
    ///< point C coordinate
    int xc,yc;
    cin>>xc>>yc;

    ///< 所有点下移2，这样可以不判断边界
    xb+=2;
    yb+=2;
    xc+=2;
    yc+=2;

    ///< 初始化马的控制点
    ans[xc][yc]=-1;
    ans[xc+1][yc-2]=-1;
    ans[xc+2][yc-1]=-1;
    ans[xc+2][yc+1]=-1;
    ans[xc+1][yc+2]=-1;
    ans[xc-1][yc+2]=-1;
    ans[xc-2][yc+1]=-1;
    ans[xc-2][yc-1]=-1;
    ans[xc-1][yc-2]=-1;

    ///< 初始化边界
    ans[2][2]=1;
    for (int i=3; i<=yb; i++) {
        if (-1!=ans[2][i]) {
            ans[2][i]=ans[2][i-1];
        }
    }
    for (int i=3; i<=xb; i++) {
        if (-1!=ans[i][2]) {
            ans[i][2]=ans[i-1][2];
        }
    }

    ///< 开始遍历
    for (int i=3; i<=xb; i++) {
        for (int j=3; j<=yb; j++) {
            if (-1!=ans[i][j]) {
                ///< 这个位置可以走
                if (-1==ans[i-1][j]&&-1==ans[i][j-1]) {
                    ans[i][j]=-1;
                } else if (-1==ans[i-1][j]&&-1!=ans[i][j-1]) {
                    ans[i][j]=ans[i][j-1];
                } else if (-1!=ans[i-1][j]&&-1==ans[i][j-1]) {
                    ans[i][j]=ans[i-1][j];
                } else {
                    ans[i][j]=ans[i-1][j]+ans[i][j-1];
                }
            }
        }
    }

    if (-1==ans[xb][yb]) {
        cout<<"0\n";
    } else {
        cout<<ans[xb][yb]<<"\n";
    }

    return 0;
}