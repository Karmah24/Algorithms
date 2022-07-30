#include <bits/stdc++.h>
using namespace std;
 
int solve() {
 
    int n, amt;
    cin >> n >> amt;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
 
    int dp[amt + 1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
 
    for (int i = 1; i <= amt; i++) {
 
        for (int j = 0; j < n; j++) {
 
            if (i < arr[j]) continue;

            if (dp[i - arr[j]] == -1) continue;

            if (dp[i] == -1) dp[i] = dp[i - arr[j]] + 1;
            else dp[i] = min(dp[i], dp[i - arr[j]] + 1);
        }
    }
    return dp[amt];
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);
 
    int T = 1;
    // cin >> T;
    while (T--) {
        cout << solve();
    }
    return 0;
}