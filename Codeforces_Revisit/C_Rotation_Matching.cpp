#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        mp[b[i]] = i;
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        int j = mp[a[i]];
        if (j >= i) res[j - i]++;
        else res[n - i + j]++;
    }
    int mx = -1;
    for (auto &e: res) mx = max(mx, e);
    return mx;
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
        cout << solve();
        cout << '\n';
    }
    return 0;
}