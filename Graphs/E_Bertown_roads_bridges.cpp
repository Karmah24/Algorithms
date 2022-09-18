#include <bits/stdc++.h>
using namespace std;
//================================================================

vector<vector<int>> adj;
vector<int> low, dep;
vector<pair<int, int>> unidirectional_edges;
bool res;

void dfs(int u, int par = -1, int d = 0) {

    dep[u] = low[u] = d;
    for (auto &v: adj[u]) {

        if (v == par) continue;
        if (dep[v] == -1) { // span edge
            dfs(v, u, d + 1);
            unidirectional_edges.push_back({u + 1, v + 1});
        }
        else if (dep[u] > dep[v]) { // back edge
            unidirectional_edges.push_back({u + 1, v + 1});
        }
        if (low[v] > dep[u]) res = false;
        low[u] = min(low[u], low[v]);
    }
}

void testcase() {

	int n, m;
    cin >> n >> m;

    adj.assign(n, vector<int>());
    low.assign(n, - 1);
    dep.assign(n, - 1);
    unidirectional_edges.clear();
    res = true;

    for (int i = 0; i < m; i++) {
       int u, v;
       cin >> u >> v;
       u--, v--;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    dfs(0);
    if (!res) {
        cout << 0;
        return;
    }
    for (auto &[u, v]: unidirectional_edges) {
        cout << u << " " << v << '\n';
    } 
}

signed main() {
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
