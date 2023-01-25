#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = (1 << 21) + 5;
const int MOD = 1e9 + 7;
//================================================================

int dp[22][N];
int n;
vector<vector<int>> a;

int solve(int i, int mask) {

    if (i == n) return mask == 0;
    int &res = dp[i][mask];
    if (res != -1) return res;

    res = 0;
    for (int j = 0; j < n; j++) {

        if (a[i][j] == 0 || !(mask & (1 << j))) continue;
        res += solve(i + 1, mask ^ (1 << j));
        res %= MOD;
    }
    return res;
}

void testcase() {

    cin >> n;
    a.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, (1 << n) - 1);
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
