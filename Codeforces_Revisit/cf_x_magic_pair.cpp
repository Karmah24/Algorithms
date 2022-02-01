#include <bits/stdc++.h>
using namespace std;
#define int long long
//=======================

bool f(int a, int b, int x) {
    if (b == 0 || x > a) return false;
    if ((a - x) % b == 0) return true;
    return f(b, a % b, x);
}
bool solve() {
    
    int a, b, x;
    cin >> a >> b >> x;
    if (a < b) swap(a, b);
    return f(a, b, x);
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}