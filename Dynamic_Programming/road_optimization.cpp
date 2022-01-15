#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

vector<int> a, d;
vector<vector<ll>> dp;

ll f(int n, int k) {

    if (n == 0) return 0;
    if (dp[n][k] != -1) return dp[n][k];
    dp[n][k] = INT_MAX;
    for (int i = max(0, n - 1 - k); i < n; i++) {
        dp[n][k] = min(dp[n][k], f(i, k - (n - i - 1)) + a[i] * (d[n] - d[i]));
    }
    return dp[n][k];
}
ll solve() {

    int n, l, k;
    cin >> n >> l >> k;
    a.resize(n);
    d.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> d[i];
    d[n] = l;
    for (int i = 0; i < n; i++) cin >> a[i];

    dp.assign(n + 1, vector<ll>(k + 1, -1));
    return f(n, k);
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while (T--) {

        cout << solve() << '\n';
    }
    return 0;
}