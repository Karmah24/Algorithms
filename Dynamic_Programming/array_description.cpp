#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}

int solve(int n, int m, int arr[]) {

    ll dp[2][m];
    memset(dp, 0, sizeof(dp));
    if (arr[0] == 0) for (int i = 0; i < m; i++) dp[0][i] = 1;
    else dp[0][arr[0] - 1] = 1;

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (arr[i] != 0) j = arr[i] - 1;

            dp[1][j] = add(dp[1][j], j == 0 ? 0 : dp[0][j - 1]);
            dp[1][j] = add(dp[1][j], dp[0][j]);
            dp[1][j] = add(dp[1][j], j == m - 1 ? 0 : dp[0][j + 1]);

            if (arr[i] != 0) break;
        }
        for (int j = 0; j < m; j++) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    if (arr[n - 1] != 0) return dp[0][arr[n - 1] - 1];
    ll res = 0;
    for (int j = 0; j < m; j++) res = add(res, dp[0][j]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solve(n, m, arr);
}