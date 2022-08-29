#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {

    int n, l, r, x;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (int i = 0; i < l; i++) {
        cin >> x;
        x--;
        v[x]++;
    }
    for (int i = 0; i < r; i++) {
        cin >> x;
        x--;
        v[x]--;
    }
    int hi = 0;
    if (l != r) hi = (l - r) / abs(l - r);

    int res = abs(l - r) / 2, parity_change = 0, color_change = 0;
    for (int i = 0; i < n; i++) {
        if (hi * v[i] > 0) {
            if (parity_change == res) color_change += abs(v[i]);
            else {
                int delta = min(res - parity_change, abs(v[i]) / 2);
                color_change += abs(v[i]) - 2 * delta;
                parity_change += delta;
            }
        }
        else {
            color_change += abs(v[i]);
        }
    }
    return res + color_change / 2;
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
        cout << solve();
        cout << '\n';
    }
    return 0;
}