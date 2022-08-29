#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        int x = *lower_bound(b.begin(), b.end(), a[i]);
        cout << x - a[i] << " ";
    }
    cout << '\n';
    int r = n - 1, l = n;
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--) {

        res[i] = b[r] - a[i];
        while (l > 0 && b[l - 1] >= a[i]) l--;
        if (i == l) r = l - 1;
    }
    for (auto &e: res) cout << e << " ";
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
        solve();
        cout << '\n';
    }
    return 0;
}