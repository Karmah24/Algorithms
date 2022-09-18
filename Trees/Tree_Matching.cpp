// Maximum matching

#include <bits/stdc++.h>
using namespace std;
//================================================================

int n;
vector<vector<int>> adj;
vector<int> par;
// max matching without including any child edge
vector<int> dp1;
// max matching including 1 child edge
vector<int> dp2;

void dfs(int u) {

	dp1[u] = dp2[u] = 0;
	for (auto &v: adj[u]) {

		if (v == par[u]) continue;
		par[v] = u;
		dfs(v);
		dp1[u] += max(dp1[v], dp2[v]);
	}
	for (auto &v: adj[u]) {

		if (v == par[u]) continue;
		dp2[u] = max(dp2[u], dp1[v] + 1 + dp1[u] - max(dp1[v], dp2[v]));
	}
}

void testcase() {

	cin >> n;

	adj.assign(n, vector<int>());
	par.assign(n, -1);
	dp1.resize(n);
	dp2.resize(n);
	for (int i = 0; i < n - 1; i++) {
	   int u, v;
	   cin >> u >> v;
	   u--, v--;
	   adj[u].push_back(v);
	   adj[v].push_back(u);
	}
	dfs(0);
	cout << max(dp1[0], dp2[0]);
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
