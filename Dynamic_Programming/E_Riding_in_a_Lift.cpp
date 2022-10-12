#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) { return ((x % MOD) + (y % MOD)) % MOD; }
ll sub(ll x, ll y) { return ((x % MOD) - (y % MOD) + MOD) % MOD; }
//================================================================

int n, a, b, k;
int dp[2][5005]; // dp[i][j] : i trips made, j current floor

int solve(int k, int i) {

    if (i < 1 || i > n) return 0;
    if (k == 0) return 1;
    int &res = dp[k][i];
    if (res != -1) return res;

    res = 0;
    for (int j = -abs(i - b) + 1; j < abs(i - b); j++) {

        if (j != 0) res = add(res, solve(k - 1, i + j));
    }
    return res;
}

void testcase() {


    cin >> n >> a >> b >> k;
    // memset(dp, -1, sizeof(dp));
    // cout << solve(k, a);

    for (int j = 1; j < n + 1; j++) dp[0][j] = 1;
    for (int i = 1; i < k + 1; i++) {

        vector<int> pfx_sum(n + 1, 0);
        for (int j = 1; j < n + 1; j++) pfx_sum[j] = add(pfx_sum[j - 1], dp[0][j]);

        for (int j = 1; j < n + 1; j++) {

            int d = abs(j - b);
            dp[1][j] = sub(pfx_sum[min(n, j + d - 1)], pfx_sum[max(1LL, j - d + 1) - 1]);
            dp[1][j] = sub(dp[1][j], dp[0][j]);
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[0][a];
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
