#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {

    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<int> mn(2);
    mn[0] = c[0], mn[1] = c[1]; 
    vector<int> pfx(2);
    pfx[0] = c[0], pfx[1] = c[1];
    int res = mn[0] * n + mn[1] * n;

    for (int i = 2; i < n; i++) {
        
        mn[i % 2] = min(mn[i % 2], c[i]);
        pfx[i % 2] += c[i];
        int up = pfx[0] + mn[0] * (n - i / 2 - 1);
        int right = pfx[1] + mn[1] * (n - (i - 1) / 2 - 1);
        res = min(res, up + right);
    }
    return res;
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