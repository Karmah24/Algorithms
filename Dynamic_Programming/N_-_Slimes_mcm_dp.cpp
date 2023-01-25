#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 4e2 + 5;
//================================================================

int dp[N][N];
int n;
vector<int> a, pfx;

int solve(int i, int j) {

    int &res = dp[i][j];
    if (res != -1) return res;
    if (i == j) return res = 0;

    res = INF;
    for (int k = i; k < j; k++) {
        int sub = solve(i, k) + solve(k + 1, j);
        int cost = pfx[j] - pfx[i - 1];
        res = min(res, sub + cost);
    }
    return res;
}

void testcase() {

    cin >> n;
    a.resize(n + 1);
    pfx.assign(n + 1, 0);
    for (int i = 1; i < n + 1; i++) cin >> a[i];
    for (int i = 1; i < n + 1; i++) pfx[i] = pfx[i - 1] + a[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(1, n);
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
