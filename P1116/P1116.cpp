//https://www.luogu.com.cn/problem/P1116
//P1116 车厢重组
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;
int data[MAXN] = {};

int bubbleSort(int arr[], int len) {
    int ans = 0;
    for (int i=0; i<len-1; i++) {
        for (int j=0; j<len-1-i; j++) {
            if (arr[j]>arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> data[i];
    }

    cout << bubbleSort(data, n) << endl;

    return 0;
}