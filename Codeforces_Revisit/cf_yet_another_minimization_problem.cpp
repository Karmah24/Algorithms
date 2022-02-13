#include <bits/stdc++.h>
using namespace std;
// #define int long long
//================================================================

int solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int sq_sum = 0, tsum = 0;
    for (auto &e: a) cin >> e;
    for (auto &e: b) cin >> e;
    for (int i = 0; i < n; i++) {
        sq_sum += a[i] * a[i] + b[i] * b[i];
        tsum += a[i] + b[i];
    }
    vector<bool> dp(tsum + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int s = tsum; s >= 0; s--) {
            if (!dp[s]) continue;
            dp[s + a[i]] = dp[s + b[i]] = true;
            dp[s] = false;
        }
    }
    int res = INT_MAX;
    for (int s = 0; s < tsum + 1; s++) {
        if (!dp[s]) continue;
        res = min(res, s * s + (tsum - s) * (tsum - s));
    }
    return res + sq_sum * (n - 2);
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}