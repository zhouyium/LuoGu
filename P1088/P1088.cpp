//https://www.luogu.com.cn/problem/P1088
//P1088 火星人

#include <cstdio>
#include <algorithm>

int a[10002] = {};
  
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int i=0;
	for (i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	
	while(m--) {
		std::next_permutation(a,a+n);
	}
	
	for (i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}