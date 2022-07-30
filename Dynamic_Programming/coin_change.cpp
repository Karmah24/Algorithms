#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}

// vector<vector<ll>> dp;

// ll solve(int n, int W, int coins[]) {

//     if (W < 0) return 0;
//     if (n < 0) return W == 0;
//     if (dp[n][W] != -1) return dp[n][W];

//     return dp[n][W] = add(solve(n - 1, W, coins), solve(n, W - coins[n], coins));
// }

int count(int n, int amt, int coins[]) {

    // dp = vector<vector<ll>>(n, vector<ll>(amt + 1, -1));
    // return solve(n - 1, amt, coins);

    ll dp[amt + 1];
    memset(dp, 0, sizeof(dp[0]));
    dp[0] = 1;

    for (int i = 0; i < n; i++) {

        for (int j = coins[i]; j <= amt; j++) {

            dp[j] = add(dp[j] , dp[j - coins[i]]);
        }
    }
    return dp[amt];
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, amt;
    cin >> n >> amt;
    int coins[n];
    for (int i = 0; i < n; i++) cin >> coins[i];
    cout << count(n, amt, coins);
    return 0;
}