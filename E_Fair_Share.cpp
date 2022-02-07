#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================

void solve() {
    int m, n;
    cin >> m;
    vector<vector<int>> mat(m, vector<int>(n));
    unordered_map<int, int> cnt;
    for (int i = 0; i < m; i++) {
        for (auto &e: mat[i]) {
            cin >> e;
            cnt[e]++;
        }
    }
    for (auto &[k, v]: cnt) if (v % 2 ==1)
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