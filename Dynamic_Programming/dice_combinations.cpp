#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}

int solve(int n) {
    
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= 6; j++) {

            if (j > i) break;
            dp[i] = add(dp[i], dp[i - j]);
        }
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    cout.setf(ios::fixed);

    int n;
    cin >> n;
    cout << solve(n);
}