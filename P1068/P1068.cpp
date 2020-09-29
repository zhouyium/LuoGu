//https://www.luogu.com.cn/problem/P1068
//P1068 分数线划定
#include <cstdio>
#include <algorithm>

struct REN {
	int k;//报名号 
	int s;//成绩 
};

REN array[5002];

bool mycmp(REN &x, REN &y) {
	if (x.s != y.s) {
		return x.s >= y.s;
	} else {
		return x.k < y.k;
	}
}

int main() {
	int n,m;
	scanf("%d %d", &n, &m);
	
	int i;
	for (i=0; i<n; i++) {
		scanf("%d %d", &array[i].k, &array[i].s);
	}
	
	std::sort(array, array+n, mycmp);
	
	int ans = 0;
	int s = array[(int)(m*1.5)-1].s;
	//查看实际人数 
	while (array[ans].s >= s) {
		ans++;
	}
	
	//打印
	printf("%d %d\n", s, ans); 
	for (i=0; i<ans; i++) {
		printf("%d %d\n", array[i].k, array[i].s);
	}
	
	return 0;
}