#include <bits/stdc++.h>
using namespace std;
//================================================================

void solve() {
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n), res(n, 0);
    map<int, vector<int>> pos;
    int sz = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (pos[a[i]].size() < k) {
            pos[a[i]].push_back(i);
            sz++;
        }
    }
    int c = 1;
    for (auto &[num, idxs]: pos) {
        for (auto &i: idxs) {
            if (c == 1 && sz < k) break;
            res[i] = c;
            c = (c % k) + 1;
            sz--;
        }
    }
    for (auto &e: res) cout << e << " ";
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}