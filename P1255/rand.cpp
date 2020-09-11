///> 随机数生成器
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
    int maxx=200;
    int minx=1;

    srand((unsigned int)time(NULL));
    int ans=rand()%(maxx-minx+1)+minx;

    cout<<ans<<"\n";

    return 0;
}