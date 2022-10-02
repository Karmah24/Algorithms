// Given a tree, and a pair of nodes(x, y), check if a path of length exactly k is possible from u to v, with or without a new edge between x and y.
// Path len u -> v = l; by going back and forth over an edge we can get any length l + 2m.
// therefore, parity of l and k should be same and l <= k
// 3 possible options for path (to get l)
// u -> v, 
// u -> x -> y -> v
// u -> y -> x -> v
// len(x -> y) = 1

#include <bits/stdc++.h>
using namespace std;
//================================================================

int n;
vector<vector<int>> adj, up;
vector<int> par, dep;

void build(int u) {
    
    up[u][0] = par[u];
    for (int i = 1; i < 20; i++) {

        int v = up[u][i - 1];
        if (v != -1) up[u][i] = up[v][i - 1];
    }
    for (auto &v: adj[u]) {

        if (v == par[u]) continue;
        par[v] = u;
        dep[v] = dep[u] + 1;
        build(v);
    }
}

int lift(int u, int k) {

    for (int i = 0; i < 20 && u != -1; i++) {

        if (k & (1 << i)) u = up[u][i];
    }
    return u;
}

int lca(int u, int v) {

    if (dep[u] < dep[v]) swap(u, v);

    u = lift(u, dep[u] - dep[v]);
    if (u == v) return u;

    for (int i = 19; i >= 0; i--) {

        if (up[u][i] != up[v][i]) {

            u = up[u][i], v = up[v][i];
        }
    }
    return up[u][0];
}

int path_len(int u, int v) {

    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

void testcase() {

    cin >> n;

    adj.assign(n, vector<int>());
    up.assign(n, vector<int>(20, -1));
    par.assign(n, -1);
    dep.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {

       int u, v;
       cin >> u >> v;
       u--, v--;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    build(0);

    int q;
    cin >> q;
    while (q--) {

        int x, y, u, v, k;
        cin >> x >> y >> u >> v >> k;
        x--, y--, u--, v--;
        
        vector<int> len(3);
        len[0] = path_len(u, v);
        len[1] = path_len(u, x) + 1 + path_len(y, v);
        len[2] = path_len(u, y) + 1 + path_len(x, v);

        bool res = false;
        for (auto &l: len) res |= (l % 2 == k % 2) && (l <= k);
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
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
