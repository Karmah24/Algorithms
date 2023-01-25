#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int K = 1e5 + 5;
const int N = 105;
const int MOD = 1e9 + 7;
//================================================================

// int dp[N][K];
// int n;
// vector<int> a;
// 
// int solve(int i, int k) {
// 
//     if (i == n) return k == 0;
//     int &res = dp[i][k];
//     if (res != -1) return res;
// 
//     res = 0;
//     for (int give = 0; give <= min(k, a[i]); give++) {
//         res += solve(i + 1, k - give);
//         res %= MOD;
//     }
//     return res;
// }

void testcase() {

    // int k;
    // cin >> n >> k;
    // a.resize(n);
    // for (int i = 0; i < n; i++) cin >> a[i];
    // 
    // memset(dp, -1, sizeof(dp));
    // cout << solve(0, k);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[n][0] = 1;

    for (int i = n - 1; i >= 0; i--) {

        vector<int> pfx(k + 2, 0);
        for (int x = 1; x < k + 2; x++) {
            pfx[x] = pfx[x - 1] + dp[i + 1][x - 1];
            pfx[x] %= MOD;
        }
        for (int j = 0; j < k + 1; j++) {

            dp[i][j] += pfx[j + 1] - pfx[max(0LL, j - a[i])];
            dp[i][j] += MOD;
            dp[i][j] %= MOD;
            // for (int give = 0; give <= min(j, a[i]); give++) {
            //     dp[i][j] += dp[i + 1][j - give];
            //     dp[i][j] %= MOD;
            // }
        }
    }
    cout << dp[0][k];
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
