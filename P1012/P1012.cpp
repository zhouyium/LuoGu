//https://www.luogu.com.cn/problem/P1012
//P1012 拼数
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string arr[21];
    int i, j;
    for (i=0; i<n; i++) {
        std::cin >> arr[i];
    }

    //排序
    for (i=0; i<n; i++) {
        for (j=i; j<n; j++) {
            if (arr[j]+arr[i] > arr[i] + arr[j]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }

    for (i=0; i<n; i++) {
        std::cout << arr[i];
    }
    std::cout <<  "\n";

    return 0;
}