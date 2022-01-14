#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}

vector<vector<ll>> dp;

ll solve(int n, int W) {

    if (n == 0) return W == 0;
    if (W < 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];

    return dp[n][W] = add(solve(n - 1, W - n), solve(n - 1, W));    
}

int countSets(int n) {

    int sum = (n * (n + 1)) / 2;

    if (sum % 2 != 0) return 0;

    dp = vector<vector<ll>>(n + 1, vector<ll>(sum + 1, -1));
    ll res = solve(n, sum / 2) / 2;
    return res;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    cout << countSets(n);
}