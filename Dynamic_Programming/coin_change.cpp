#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}

// vector<vector<ll>> dp;

// ll solve(int n, int W, int arr[]) {

//     if (W < 0) return 0;
//     if (n < 0) return W == 0;
//     if (dp[n][W] != -1) return dp[n][W];

//     return dp[n][W] = add(solve(n - 1, W, arr), solve(n, W - arr[n], arr));
// }

int count(int n, int amt, int arr[]) {

    // dp = vector<vector<ll>>(n, vector<ll>(amt + 1, -1));
    // return solve(n - 1, amt, arr);

    ll dp[2][amt + 1];
    memset(dp[0], 0, sizeof(dp[0]));
    dp[0][0] = dp[1][0] = 1;

    for (int i = 0; i < n; i++) {

        for (int j = 1; j <= amt; j++) {

            if (j < arr[i]) dp[1][j] = dp[0][j];
            else dp[1][j] = add(dp[0][j] , dp[1][j - arr[i]]);
        }
        for (int k = 0; k <= amt; k++) dp[0][k] = dp[1][k];
    }
    return dp[1][amt];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, amt;
    cin >> n >> amt;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << count(n, amt, arr);
    return 0;
}