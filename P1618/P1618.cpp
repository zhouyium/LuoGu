//https://www.luogu.com.cn/problem/P1618
//P1618 三连击（升级版）
/*暴力*/
#include <cstdio>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int i, x, y, z;
	bool flag = false;
	//三位数而且每位不能相同最小123，最大987 
	for (i=1; i<=987; i++) {
		x = i * a;
		y = i * b;
		z = i * c;
		
		//必须是三位数，满足每位不同，
		if (x>987 || y>987 || z>987 || x<123 || y<123 || z<123) {
			continue;
		}
		if ((x/100+x/10%10+x%10+y/100+y/10%10+y%10+z/100+z/10%10+z%10==1+2+3+4+5+6+7+8+9) && (((x/100)*(x/10%10)*(x%10)*(y/100)*(y/10%10)*(y%10)*(z/100)*(z/10%10)*(z%10))==1*2*3*4*5*6*7*8*9)) {
			flag = true;
			printf("%d %d %d\n", x, y, z);
		}
	}
	
	if (flag == false) {
		printf("No!!!\n");
	}
	return 0;
}