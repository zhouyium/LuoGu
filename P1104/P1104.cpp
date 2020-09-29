//https://www.luogu.com.cn/problem/P1104
//P1104 生日
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2+4;
typedef struct _REN {
	int idx;
	char mz[22];//名字 
	int year;//年 
	int month;//月 
	int day;//日 
} REN;
REN nums[MAXN];

bool mycmp(const REN &x, const REN &y) {
	if (x.year!=y.year) {
		return x.year<y.year;
	} else if (x.month!=y.month) {
		return x.month<y.month;
	} else if (x.day!=y.day) {
		return x.day<y.day;
	} else {
		return x.idx>y.idx;
	}
}

int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		nums[i].idx=i;
		cin>>nums[i].mz>>nums[i].year>>nums[i].month>>nums[i].day;
	} 
	
	sort(nums+1, nums+n+1, mycmp);
	
	for(int i=1; i<=n; i++) {
		cout<<nums[i].mz<<"\n";
	}
	
	return 0;
}
