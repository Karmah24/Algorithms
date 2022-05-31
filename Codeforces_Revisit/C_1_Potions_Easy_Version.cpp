#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(2, vector<int>(n + 1, -1));
    dp[0][0] = dp[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[0][j] >= 0) {
                dp[1][j] = max(dp[1][j], dp[0][j]);
            }
            if (dp[0][j - 1] >= 0 && dp[0][j - 1] + a[i - 1] >= 0) {
                dp[1][j] = max(dp[1][j], dp[0][j - 1] + a[i - 1]);
            }
            if (dp[1][j] < 0) break;
        }
        dp[0] = dp[1];
    }
    for (int j = n; j >= 0; j--) {
        if (dp[1][j] >= 0) return j;
    }
    return 0;
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