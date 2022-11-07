#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> a[i];
    for (int i = 1; i < n + 1; i++) cin >> b[i];

    vector<int> pfx(n + 1);
    for (int i = 1; i < n + 1; i++) pfx[i] = pfx[i - 1] + a[i] * b[i];

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n + 1; i++) dp[i][i] = a[i] * b[i];
    for (int l = n - 1; l >= 1; l--) {
        for (int r = l + 1; r < n + 1; r++) { 
            dp[l][r] = dp[l + 1][r - 1] + a[l] * b[r] + a[r] * b[l];
        }
    }
    int res = pfx[n];
    for (int l = 1; l < n + 1; l++) {
        for (int r = l + 1; r < n + 1; r++) {

            int diff = dp[l][r] - (pfx[r] - pfx[l - 1]);
            res = max(res, pfx[n] + diff);
        }
    }
    cout << res;
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
