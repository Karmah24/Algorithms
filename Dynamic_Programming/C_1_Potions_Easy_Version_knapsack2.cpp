#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 2e12;
//================================================================

int n;
vector<int> a;
int dp[2005][2005];

int solve(int n, int k) {

    if (n < 0) {
        if (k == 0) {
            return 0;
        }
        return -INF;
    }
    int &res = dp[n][k];
    if (res != -INF - 1) return res;

    int ifin = -INF, ifout = solve(n - 1, k);
    if (k > 0) {
        int x = solve(n - 1, k - 1);
        if (x >= 0) ifin = x + a[n];
    }
    return res = max(ifin, ifout);
}

void testcase() {

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) dp[i][j] = -INF - 1;
    }
    int k = n;
    for (; k >= 0; k--) {

        solve(n - 1, k);
        if (dp[n - 1][k] >= 0) break;
    }
    cout << k;
}

int testcase1() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(2, vector<int>(n + 1, -1));
    dp[0][0] = dp[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[0][j] >= 0) {
                dp[1][j] = max(dp[1][j], dp[0][j]);
            }
            if (dp[0][j - 1] >= 0 && dp[0][j - 1] + a[i - 1] >= 0) {
                dp[1][j] = max(dp[1][j], dp[0][j - 1] + a[i - 1]);
            }
            if (dp[1][j] < 0) break;
        }
        dp[0] = dp[1];
    }
    for (int j = n; j >= 0; j--) {
        if (dp[1][j] >= 0) return j;
    }
    return 0;
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
