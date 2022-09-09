#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 5;
//================================================================

vector<vector<pair<int, int>>> adj;
vector<bool> vis;
vector<int> dep, par;
string res;

void dfs(int u, int d = 0) {

	vis[u] = true;
	dep[u] = d;

	for (auto &[v, e]: adj[u]) {

		if (vis[v]) continue;
		res[e] = '1'; // span edge
		par[v] = u;
		dfs(v, d + 1);
	}
}

void testcase() {
    
	int n, m;
	cin >> n >> m;
	adj.assign(n, vector<pair<int, int>>());
	vis.assign(n, false);
	dep.assign(n, 0);
	par.resize(n);

	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges.push_back({u, v});
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	res.assign(m, '0');
	dfs(0);

	map<int, int> cnt;
	for (int i = 0; i < m; i++) {
		
		if (res[i] == '0') {  // back edge
			cnt[edges[i].first]++;
			cnt[edges[i].second]++;
		}
	}
	// 3 back edges - possibility of a cycle
	if (cnt.size() == 3) {
		int mx = -INF, mn = INF;
		for (auto &[k, v]: cnt) {
			mx = max(mx, v);
			mn = min(mn, v);
		}
		// 3 back edges forming a cycle (a-b, b-c, c-a)
		if (mx == mn && mx == 2) {

			vector<int> back_edges;
			for (auto &[v, c]: cnt) back_edges.push_back(v);
			sort(back_edges.begin(), back_edges.end(), [&](int a, int b){
				return dep[a] < dep[b];
			});
			int c = back_edges.back();
			int i, j;  // edges to be switched
			for (auto &[v, e]: adj[c]) {

				if (res[e] == '0') i = e;
				else if (v == par[c]) j = e;
			}
			res[i] = '1';
			res[j] = '0';
		}
	}
	cout << res;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("../input.txt", "r", stdin);
	  freopen("../output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
