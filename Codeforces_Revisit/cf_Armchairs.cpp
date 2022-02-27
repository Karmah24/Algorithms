#include <bits/stdc++.h>
using namespace std;
//================================================================

int solve() {
    int n, in;
    cin >> n;
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        cin >> in;
        if (in) x.push_back(i);
        else y.push_back(i);
    }
    int dp[x.size() + 1][y.size() + 1];
    for (int i = 0; i <= y.size(); i++) dp[0][i] = 0;
    for (int i = 1; i <= x.size(); i++) {
        dp[i][i] = dp[i - 1][i - 1] + abs(x[i - 1] - y[i - 1]);
    }
    for (int i = 1; i <= x.size(); i++) {
        for (int j = i + 1; j <= y.size(); j++) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(x[i - 1] - y[j - 1]));
        }
    }
    return dp[x.size()][y.size()];
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