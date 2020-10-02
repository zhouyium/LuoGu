//https://www.luogu.com.cn/problem/P2089
//P2089 烤鸡

/*
直接暴力枚举即可。
*/
#include <cstdio>
#include <queue>
#include <string>
int main() {
	int n;
	scanf("%d", &n);
	
	int ans = 0;
	std::queue<char *> q;
	char *str;
	//暴力
	int a,b,c,d,e,f,g,h,i,j;
	for (a=1; a<=3; a++) {
		for (b=1; b<=3; b++) {
			for (c=1; c<=3; c++) {
				for (d=1; d<=3; d++) {
					for (e=1; e<=3; e++) {
						for (f=1; f<=3; f++) {
							for (g=1; g<=3; g++) {
								for (h=1; h<=3; h++) {
									for (i=1; i<=3; i++) {
										for (j=1; j<=3; j++) {
											if (a+b+c+d+e+f+g+h+i+j==n) {
												ans++;
												str = new char [500];
												sprintf(str,"%d %d %d %d %d %d %d %d %d %d", a,b,c,d,e,f,g,h,i,j);
												q.push(str);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	printf("%d\n", ans);
	while (q.empty()!=true) {
		str = q.front();
		printf("%s\n", str);
		delete [] str;
		q.pop();
	}
	
	return 0;
}