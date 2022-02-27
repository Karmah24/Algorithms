#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int dp[n][n];
    for (int i = 0; i < n; i++) dp[i][i] = 0;
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + a[r] - a[l];
        }
    }
    return dp[0][n - 1];
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}