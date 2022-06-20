#include <bits/stdc++.h>
using namespace std;
//================================================================

int solve() {
    
    int n, x;
    cin >> n;

    int even = 0, mn_ops = LLONG_MAX;
    for (int i = 0; i < n; i++) {

        cin >> x;
        if (x % 2 != 0) continue;
        even++;
        int ops = 0;
        while (x % 2 == 0) {
            x /= 2;
            ops++;
        }
        mn_ops = min(mn_ops, ops);
    }
    if (even != n) return even;
    return mn_ops + even - 1;
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
        cout << solve() << '\n';
    }
    return 0;
}