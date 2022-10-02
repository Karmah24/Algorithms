#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

void testcase() {

	int n, m, k;
    cin >> n >> m >> k;
	vector<vector<int>> edges(m + 1);

	for (int i = 1; i <= m; i++) {

		int u, v, l;
		cin >> u >> v >> l;
		edges[i] = {u, v, l};
	}
	vector<int> seq(k + 1);
	for (int i = 1; i <= k; i++) cin >> seq[i];

	int dp[n + 1];
	for (auto &e: dp) e = INF;
	dp[1] = 0;

	for (int i = 1; i <= k; i++) {

		auto tmp = edges[seq[i]];
		int u = tmp[0], v = tmp[1], l = tmp[2];
		if (dp[u] == INF) continue;
		dp[v] = min(dp[v], dp[u] + l);
	}
	if (dp[n] < INF) cout << dp[n];
	else cout << -1;
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
