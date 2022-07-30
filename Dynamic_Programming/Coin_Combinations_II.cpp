#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, amt;
    cin >> n >> amt;
    int coins[n];
    for (int i = 0; i < n; i++) cin >> coins[i];

    ll dp[amt + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 0; i < n; i++) {

        for (int j = coins[i]; j <= amt; j++) {

            dp[j] = add(dp[j] , dp[j - coins[i]]);
        }
    }
    cout << dp[amt];
}