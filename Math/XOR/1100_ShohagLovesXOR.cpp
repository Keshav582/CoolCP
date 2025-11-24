/*
Problem link: https://codeforces.com/contest/2039/problem/C1
It is evident that brute force won't work since m is really large.
Let's consider m is always very big.
When y is <=x we can simply check all y if they satisfy the condition
When y>x, let's say z is the XOR of x and y, if z has to divide either x or y
then z has to be <=y/2 and x/2, which would mean z's MSB has to be at least one less than x or y's MSB
but if y's MSB is larger than x's MSB, z's MSB will definitely be equal to y's MSB, which would mean it can't divide y and since z would be greater than x it of course won't divide x
this breaks the question's condition. So what we get from here is y's MSB can't be greater than x, therefore y can't be >2*x, so our answer space is just [1, min(m, 2*x)]

TAKEAWAY:
1. if x>0 and y>0, XOR(x, y)!=x and XOR(x, y)!=y
2. for any numbers x and y, if MSB of one is greater than the other, there XOR will always result in a number bigger than the smaller one
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/input.txt", "r", stdin);
    freopen("/Users/keshavpaliwal/Desktop/Everything/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int x, m;
        cin >> x >> m;
        int ans = 0;
        for(int i=1;i<=min(m, 2*x);i++) {
            if(i!=x && (x%(x^i)==0 || i%(x^i)==0)) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}