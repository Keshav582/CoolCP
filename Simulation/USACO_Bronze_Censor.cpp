// https://usaco.org/index.php?page=viewproblem2&cpid=526
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    setIO("censor");
    string s, t;
    cin >> s;
    cin >> t;
    string ans = "";
    for(int i=0;i<s.size();i++) {
        ans+=s[i];
        if(ans.size()>=t.size() && ans.substr(ans.size()-t.size())==t) {
            for(int j=0;j<t.size();j++) ans.pop_back();
        }
    }
    cout << ans << '\n';
    return 0;
}