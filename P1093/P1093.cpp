//https://www.luogu.com.cn/problem/P1093
//P1093 奖学金

#include <bits/stdc++.h>

using namespace std;

typedef struct _Info {
	int id;
    int yw;//语文成绩
    int sx;//数学成绩
    int en;//英文成绩
	int tot;
} INFO;

const int MAXN=3e2+4;
INFO score[MAXN];

bool mycmp(const INFO &x, const INFO &y) {
    if (x.tot == y.tot) {
        //总分相等
        if (x.yw==y.yw) {
            //语文成绩相等
            return x.id<y.id;
        } else {
            return x.yw>y.yw;
        }
    } else {
        return x.tot>y.tot;
    }
}

int main() {
    int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
        cin>>score[i].yw>>score[i].sx>>score[i].en;
        score[i].id = i;
        score[i].tot = score[i].yw+score[i].sx+score[i].en;
    }

    sort(score+1, score+1+n, mycmp);

	for (int i=1; i<=5; i++) {
		cout<<score[i].id<<" "<<score[i].tot<<endl;
    }
	return 0;
}