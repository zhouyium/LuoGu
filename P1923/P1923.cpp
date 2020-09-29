//https://www.luogu.com.cn/problem/P1923
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5e6+2;
int nums[MAXN];

int main() {
    int n,m;
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    nth_element(nums, nums+m, nums+n);

    printf("%d\n", nums[m]);

    return 0;
}