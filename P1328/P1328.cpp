//https://www.luogu.com.cn/problem/P1328
#include <iostream>
using namespace std;

const int MAXN = 2e2+4;
int a[MAXN];
int b[MAXN];

int main() {
    int n, na, nb;
    cin>>n>>na>>nb;
    for (int i=0; i<na; i++) {
        cin>>a[i];
    }
    for (int i=0; i<nb; i++) {
        cin>>b[i];
    }

    int ansa=0;
    int ansb=0;
    int idxa=0;
    int idxb=0;
    for (int i=0; i<n; i++) {
        if (0==a[idxa]) {
            //a 剪刀
            if (0==b[idxb]) {
                //剪刀 vs 剪刀
            } else if (1==b[idxb]) {
                //剪刀 vs 石头
                //剪刀 lose
                ansb++;
            } else if (2==b[idxb]) {
                //剪刀 vs 布
                //剪刀 win
                ansa++;
            } else if (3==b[idxb]) {
                //剪刀 vs 蜥蜴人
                //剪刀 win
                ansa++;
            } else {
                //剪刀 vs 斯波克
                //剪刀 lose
                ansb++;
            }
        } else if (1==a[idxa]) {
            //a 石头
            if (0==b[idxb]) {
                //石头 vs 剪刀
                //石头 win
                ansa++;
            } else if (1==b[idxb]) {
                //石头 vs 石头
            } else if (2==b[idxb]) {
                //石头 vs 布
                //石头 lose
                ansb++;
            } else if (3==b[idxb]) {
                //石头 vs 蜥蜴人
                //石头 win
                ansa++;
            } else {
                //石头 vs 斯波克
                //石头 lose
                ansb++;
            }
        } else if (2==a[idxa]) {
            //a 布
            if (0==b[idxb]) {
                //布 vs 剪刀
                //布 lose
                ansb++;
            } else if (1==b[idxb]) {
                //布 vs 石头
                //布 win
                ansa++;
            } else if (2==b[idxb]) {
                //布 vs 布
            } else if (3==b[idxb]) {
                //布 vs 蜥蜴人
                //布 lose
                ansb++;
            } else {
                //布 vs 斯波克
                //布 win
                ansa++;
            }
        } else if (3==a[idxa]) {
            //a 蜥蜴人
            if (0==b[idxb]) {
                //蜥蜴人 vs 剪刀
                //蜥蜴人 win
                ansb++;
            } else if (1==b[idxb]) {
                //蜥蜴人 vs 石头
                //蜥蜴人 lose
                ansb++;
            } else if (2==b[idxb]) {
                //蜥蜴人 vs 布
                //蜥蜴人 win
                ansa++;
            } else if (3==b[idxb]) {
                //蜥蜴人 vs 蜥蜴人
            } else {
                //蜥蜴人 vs 斯波克
                //蜥蜴人 win
                ansa++;
            }
        } else {
            //a 斯波克
            if (0==b[idxb]) {
                //斯波克 vs 剪刀
                //斯波克 win
                ansa++;
            } else if (1==b[idxb]) {
                //斯波克 vs 石头
                //斯波克 win
                ansa++;
            } else if (2==b[idxb]) {
                //斯波克 vs 布
                //斯波克 lose
                ansb++;
            } else if (3==b[idxb]) {
                //斯波克 vs 蜥蜴人
                //斯波克 lose
                ansb++;
            } else {
                //b 斯波克
            }
        }

        idxa=(idxa+1)%na;
        idxb=(idxb+1)%nb;
    }
    
    cout<<ansa<<" "<<ansb<<"\n";

    return 0;
}