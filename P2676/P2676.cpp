//https://www.luogu.com.cn/problem/P2676
//P2676 [USACO07DEC]Bookshelf B
#include <bits/stdc++.h>
using namespace std;

const int MAXN=2e4+4;
int nums[MAXN];

int main() {
	int n, b;
	cin>>n>>b;
	for (int i=1; i<=n; i++) {
		cin>>nums[i];
	}
	
	sort(nums+1, nums+n+1);
	
	int ans=0;
	for (int i=n; i>0; i--) {
		if (b>0) {
			b-=nums[i];
			ans++;
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
