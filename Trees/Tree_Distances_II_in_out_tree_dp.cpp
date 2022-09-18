// For each node find sum of distances to all other nodes.
// Calculate sum of distance to nodes in subtree.
// for nodes outside subtree, res[par] - sum of all dis from par to subtree of u will give res[u]

#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int n;
vector<vector<int>> adj;
vector<int> par, sub, res;

void dfs1(int u) {

    for (auto &v: adj[u]) {

        if (v == par[u]) continue;
        par[v] = u;
        dfs1(v);
        sub[u] += sub[v];
        res[u] += res[v] + sub[v];
    }
}

void dfs2(int u, int out) {

    res[u] += out + n - sub[u];
    for (auto &v: adj[u]) {

        if (v == par[u]) continue;
        dfs2(v, res[u] - res[v] - sub[v]);
    }
}

void testcase() {

    cin >> n;

    adj.assign(n, vector<int>());
    par.assign(n, -1);
    for (int i = 0; i < n - 1; i++) {
       int u, v;
       cin >> u >> v;
       u--, v--;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    sub.assign(n, 1);
    res.assign(n, 0);
    dfs1(0);
    dfs2(0, 0);

    for (auto &e: res) cout << e << " ";
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
