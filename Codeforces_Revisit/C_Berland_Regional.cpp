#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {

    int n, t = 0;
    cin >> n;
    vector<int> u(n);
    vector<vector<int>> s(n);
    for (int i = 0; i < n; i++) cin >> u[i];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s[u[i] - 1].push_back(x);
    }
    for (auto &v: s) {
        sort(v.rbegin(), v.rend());
        for (int i = 1; i < v.size(); i++) v[i] += v[i - 1];
    }
    sort(s.rbegin(), s.rend(), [](auto v1, auto v2){
        return v1.size() < v2.size();
    });
    int i;
    for (i = 1; i <= n; i++) {
        if (i > s.front().size()) break;
        int res = 0;
        for (auto &v: s) {
            int sz = v.size();
            if (sz < i) break;
            res += v[sz - (sz % i) - 1];
        }
        cout << res << " ";
    }
    for (; i <= n; i++) cout << "0 ";
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
        solve();
        cout << '\n';
    }
    return 0;
}