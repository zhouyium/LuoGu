//https://www.luogu.com.cn/problem/P1177
//P1177 【模板】快速排序
#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e5+4;
int sz[MAXN];

//快速排序
void quickSort(int array[], int low, int high) {
    int i=low;
    int j=high;
    if (i>=j) {
        return;
    }

    int temp=array[low];
    while (i<j) {
        while (array[j]>=temp && i<j) {
            j--;
        }
        while (array[i]<=temp && i<j) {
            i++;
        }
        if (i<j) {
            swap(array[i], array[j]);
        }
    }

    swap(array[low], array[i]);
    quickSort(array, low, i-1);
    quickSort(array, i+1, high);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d", &sz[i]);
    }

#if 1
    sort(sz+1, sz+n+1);
#else
    //特么TLE了。我去
    quickSort(sz, 1, n);
#endif

    for (int i=1; i<=n; i++) {
        printf("%d ", sz[i]);
    }
    printf("\n");

    return 0;
}