#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 2e3 + 5;
//================================================================

int dp[N][N];
int nx[N][N];
vector<vector<int>> adj;
int n;
string s;

void dfs(int u, int p, int src) {
	
	nx[u][src] = p;
	for (auto &v: adj[u]) {
		if (v != p) dfs(v, u, src);
	}
}

int solve(int u, int v) {

	if (u == v) return 1;
	int &res = dp[u][v];
	if (res != -1) return res;

	int nu = nx[u][v], nv = nx[v][u];
	if (s[u] == s[v]) {
		res = 2;
		if (nu != v || nv != u) res += solve(nu, nv);
		return res;
	}
	return res = max(solve(nu, v), solve(u, nv));
}

void testcase() {

	cin >> n >> s;
	adj.assign(n, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int u = 0; u < n; u++) dfs(u, u, u);
	memset(dp, -1, sizeof(dp));
	int res = 1;
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) res = max(res, solve(u, v));
	}
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
