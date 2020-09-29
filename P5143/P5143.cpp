//https://www.luogu.com.cn/problem/P5143
//P5143 攀爬者
#include <bits/stdc++.h>
using namespace std;

typedef struct _zb {
	int x;
	int y;
	int z;
} ZB;

const int MAXN=5e4+4;
ZB nums[MAXN];

bool mycmp(const ZB &x, const ZB &y) {
	return x.z<y.z;
}

int main() {
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>nums[i].x>>nums[i].y>>nums[i].z;
	}
	
	sort(nums+1, nums+n+1, mycmp);
	
	double ans=0;
	for (int i=2; i<=n; i++) {
		ans+=sqrt((nums[i].x-nums[i-1].x)*(nums[i].x-nums[i-1].x)+(nums[i].y-nums[i-1].y)*(nums[i].y-nums[i-1].y)+(nums[i].z-nums[i-1].z)*(nums[i].z-nums[i-1].z));
	}
	
	cout<<fixed<<setprecision(3)<<ans<<"\n";
	
	return 0;
}
