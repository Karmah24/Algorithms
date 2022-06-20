#include <bits/stdc++.h>
using namespace std;
//================================================================

void solve() {
    
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n1\n";
        return;
    }
    if (n % 2 == 1) {
        cout << "-1\n";
        return;
    }
    int p = 1;
    while (p <= n) p *= 2;
    vector<int> res(n);
    vector<bool> vis(n, 0);
    for (int i = n; i > 0; i--) {

        if (vis[i - 1]) continue;
        while (i * 2 < p) p /= 2;

        int partner = p - 1 - i;
        res[i - 1] = partner;
        res[partner - 1] = i;
        vis[i - 1] = vis[partner - 1] = 1;
    }
    for (int i = 0; i < n; i++) cout << i + 1 << " ";
    cout << '\n';
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << '\n';
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