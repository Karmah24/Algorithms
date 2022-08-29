#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<int> pfx(n);
    pfx[0] = a[0].first;
    for (int i = 1; i < n; i++) pfx[i] = pfx[i - 1] + a[i].first;
    vector<bool> res(n, false);
    res[a[n - 1].second] = true;
    int i;
    for (i = n - 2; i >= 0; i--) {
        if (pfx[i] < a[i + 1].first) break;
        res[a[i].second] = true;
    }
    cout << n - 1 - i << '\n';
    for (int i = 0; i < n; i++) if (res[i]) cout << i + 1 << " ";
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