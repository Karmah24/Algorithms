#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================

int solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> min_idx(2 * n + 1);
    for (auto &e: a) cin >> e;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        min_idx[b[i]] = i;
    }
    for (int p = 2 * n - 2; p > 0; p -= 2) {
        min_idx[p] = min(min_idx[p], min_idx[p + 2]);
    }
    int res = n;
    for (int i = 0; i < n; i++) {
        res = min(res, i + min_idx[a[i] + 1]);
    }
    return res;
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