#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================

void solve() {
    int n, m, q;
    cin >> n >> m;
    vector<vector<bool>> grid(n, vector<bool>(m));
    set<int> undeterminable;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char ch;
            cin >> ch;
            grid[r][c] = ch == '.';
            if (c != 0 && r != 0 && !(grid[r - 1][c] || grid[r][c - 1])) undeterminable.insert(c);
        }
    }
    cin >> q;
    if (undeterminable.empty()) {
        while (q--) cout << "YES\n";
        return;
    }
    while (q--) {
        int c1, c2;
        cin >> c1 >> c2;
        c1--;
        auto l = undeterminable.upper_bound(c1);
        auto r = undeterminable.lower_bound(c2);
        if (l == r) cout << "YES\n";
        else cout << "NO\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}