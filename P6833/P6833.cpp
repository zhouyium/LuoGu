//https://www.luogu.com.cn/problem/P6833
#include <bits/stdc++.h>

/*
注意距离必须使用 long long。这里卡了一下。
根据题目数据最大范围
矩阵是 1000*1000，也就是 1e6
Rij是 1e9，也就是说，最大的距离就是 1e6 个 1e9 之和，也就是 1e15，超过了 int 范围。
本题是两个终点。这样我们可以将路线分为三个部分：
(n,a)->(i,j)，其中(i,j)是分叉点
(i,j)->(1,b)
(i,j)->(1,c)
也就是说最小距离为这三段距离之和。但是要找这个分界点(i,j)比较困难。
我们可以换一个思路，我们分别计算出：
1、从(n,a)出发遍历全图的距离
2、从(1,b)出发遍历全图的距离
3、从(1,c)出发遍历全图的距离
那么从(n,a)->(1,b)和(n,a)->(1,c)的最小距离。就应该是这三个距离最小值之和，但是这个和多了 2*r[i][j]。
*/
using namespace std;

struct NODE {
    int x,y;//坐标
    long long dis;

    //重载操作符，用于排序
    bool operator < (const NODE &a) const {
        return a.dis<dis;
    }
};

const int MAXN=1e3+4;
const int MAXM=1e3+4;

bool vis[MAXN][MAXM];
long long r[MAXN][MAXM];
long long disA[MAXN][MAXM];//从A点出发到所有点距离
long long disB[MAXN][MAXM];//从B点出发到所有点距离
long long disC[MAXN][MAXM];//从C点出发到所有点距离

int n,m;

const NODE moves[4]={{0,1},{0,-1},{1,0},{-1,0}};

//
void bfs(const NODE &qd, long long dis[MAXN][MAXM]) {
    memset(vis, 0, sizeof(vis));
    //memset(dis, LONG_LONG_MAX, sizeof(dis));

    //更新起点距离
    dis[qd.x][qd.y]=qd.dis;

    priority_queue<NODE> q;
    q.push(qd);

    while (!q.empty()) {
        //获取当前点
        NODE cur=q.top();
        q.pop();

        //可见性判断
        if (true==vis[cur.x][cur.y]) {
            continue;
        }
        vis[cur.x][cur.y] = true;

        //四个方向走
        for (int i=0; i<4; i++) {
            int nx = cur.x+moves[i].x;
            int ny = cur.y+moves[i].y;
            long long nd = dis[cur.x][cur.y]+r[nx][ny];

            //合法性判断
            if (nx<1 || nx>n || ny<1 || ny>m) {
                //出了边界
                continue;
            }
            if (dis[nx][ny]>nd) {
                //更新数据
                q.push((NODE){nx, ny, nd});

                //更新距离数据
                dis[nx][ny]=nd;
            }
        }
    }
}

int main() {
    int a,b,c;
    cin>>n>>m>>a>>b>>c;

    //注意题目表示的坐标系
    for (int i=n; i>0; i--) {
        for (int j=1; j<=m; j++) {
            cin>>r[i][j];
            disA[i][j]=LONG_LONG_MAX;
            disB[i][j]=LONG_LONG_MAX;
            disC[i][j]=LONG_LONG_MAX;
        }
    }

    //从(n,a)出发到所有位置的距离
    NODE qd={n, a, r[n][a]};
    bfs(qd, disA);
    
    //从(1,b)出发到所有位置的距离
    qd={1, b, r[1][b]};
    bfs(qd, disB);

    //从(1,c)出发到所有位置的距离    
    qd={1, c, r[1][c]};
    bfs(qd, disC);

    //在 disA 和 disB 中找最短路径
    long long ans=LONG_LONG_MAX;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ans=min(ans, disA[i][j]+disB[i][j]+disC[i][j]-2*r[i][j]);
        }
    }
    cout<<ans<<"\n";

    return 0;
}