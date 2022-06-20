#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {
    
    int n;
    cin >> n;
    vector<int> b(n + 1);
    int x = 0;
    for (int i = 0; i <= n; i++) {
        cin >> b[i];
        x ^= b[i];
    }
    if (n % 2 == 1) {
        bool f = 1;
        for (auto &e: b) {
            if (e == x && f) {
                f = 0;
                continue;
            }
            cout << (x ^ e) << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) cout << (b[0] ^ b[i]) << " ";
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