//https://www.luogu.com.cn/problem/P1149
//P1149 火柴棒等式

//暴力
#include <cstdio> 
const int MAXN = 1111;

//判断是否成立 
int match(int x) {
	int ans = 0;
	//组成对应数字需要的火柴数 
	int num[] = {6,2,5,5,4,5,6,3,7,6};
	if (x == 0) {
		return num[0];
	}
	while (x) {
		ans += num[x%10];
		x /= 10;
	}
	return ans;
}
int main() {
	//一个整数n(n<=24)
	int n;
	scanf("%d", &n);
	//+和=要用了4个火柴
	n = n - 4; 
	
	int ans = 0;
	int i, j;//两个加数 
	for (i=0; i<= MAXN; i++) {
		for (j=0; j<= MAXN; j++) {
			if (match(i+j)+match(i)+match(j)==n) {
				ans++;
			}
		}
	}
	
	printf("%d\n", ans);
}