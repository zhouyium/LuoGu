//https://www.luogu.com.cn/problem/P6832
//子弦
//求最多非空字串次数。我们可以知道单个字符构成的字串，肯定是出现次数最多的。
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;

    int cnt[26]={};
    for (int i=0; i<s.length(); i++) {
        cnt[s[i]-'a']++;
    }

    int ans=0;
    for (int i=0; i<26; i++) {
        if (cnt[i]>ans) {
            ans=cnt[i];
        }
    }

    cout<<ans<<"\n";

    return 0;
}