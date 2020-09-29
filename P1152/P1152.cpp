//https://www.luogu.com.cn/problem/P1152 
//P1152 欢乐的跳
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+4;
int nums[MAXN]; 
int jolly[MAXN];

int main() {
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>nums[i];
	}
	
	for (int i=2; i<=n; i++) {
		int x=abs(nums[i]-nums[i-1]);
		if (x>n-1 || 0!=jolly[x]) {
			cout<<"Not jolly\n";
			return 0;
		}
		jolly[x]++;
	}
	
	for (int i=1; i<n; i++) {
		if (0==jolly[i]) {
			cout<<"Not jolly\n";
			return 0;
		}
	}
	cout<<"Jolly\n";
	
	return 0;
}
