#include <bits/stdc++.h>
using namespace std;
//================================================================

void solve() {
    
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n), res(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<pair<int, int>> st;
    for (int i = 1; i <= m; i++) st.insert({0, i});
    for (int i = 0; i < n; i++) {
        auto [sm, idx] = *st.begin();
        res[i] = idx;
        st.erase(st.begin());
        st.insert({sm + a[i], idx});
    }
    if (((*st.rbegin()).first - (*st.begin()).first) > x) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (auto &e: res) cout << e << " ";
    }
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