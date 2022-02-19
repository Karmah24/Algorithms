#include <bits/stdc++.h>
using namespace std;
// #define int long long
//================================================================

bool solve() {
    int u, v;
    cin >> u >> v;
    if (v < u) return false;
    int x = 1, v_set_cnt = 0, u_set_cnt = 0;
    for (int i = 0; i < 30; i++) {
        if (v & x) v_set_cnt++;
        if (u & x) u_set_cnt++;
        if (v_set_cnt > u_set_cnt) return false;
        x = x << 1;
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}