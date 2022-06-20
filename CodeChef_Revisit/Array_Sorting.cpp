#include <bits/stdc++.h>
using namespace std;
//================================================================

void solve() {
    
    int n;
    cin >> n;
    vector<int> a(n), p(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    vector<vector<int>> res;
    for (int i = n; i >= 1; i--) {

        for (int j = p[i]; j < i - 1; j++) {
            res.push_back({j, j + 1});
            swap(a[j], a[j + 1]);
            p[a[j + 1]] = j + 1;
            p[a[j]] = j;
        }
    }
    cout << res.size() << "\n";
    for (auto &v: res) {
        cout << v[0] + 1 << " " << v[1] + 1<< '\n';
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
    }
    return 0;
}