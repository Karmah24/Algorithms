#include <bits/stdc++.h>
using namespace std;
//================================================================
vector<vector<int>> dp;

bool f(int W, int n, vector<int> &arr) {
    if (n < 0) return W == 0;
    if (W < 0) return false;
    if (dp[n][W] != -1) return dp[n][W];
    return dp[n][W] = f(W, n - 1, arr) || f(W - arr[n], n - 1, arr);
}
void solve() {
    int n, tsum = 0;
    cin >> n;
    vector<int> arr(n);
    pair<int, int> res = {-1, 2000};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tsum += arr[i];
        int fsb = arr[i] & (~(arr[i] - 1));
        if (fsb < res.second) res = {i + 1, fsb};
    }
    dp.assign(n, vector<int>(tsum / 2 + 1, -1));
    if (tsum % 2 != 0 || !f(tsum / 2, n - 1, arr)) {
        cout << 0;
        return;
    }
    cout << "1\n" << res.first;
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
        solve();
    }
    return 0;
}