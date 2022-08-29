#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {
    
    int n, ca, cb;
    cin >> ca >> cb >> n;
    vector<int> a(n), b(n);
    vector<int> freq_a(ca + 1), freq_b(cb + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq_a[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        freq_b[b[i]]++;
    }
    int res = 0, k = n;
    for (int i = 0; i < n; i++) {
        res += n - freq_a[a[i]] - freq_b[b[i]] + 1;
    }
    return res / 2;
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
        cout << solve();
        cout << '\n';
    }
    return 0;
}