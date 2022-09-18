#include <bits/stdc++.h>
using namespace std;
//================================================================

vector<vector<int>> adj, up;
vector<int> dep;

void dfs(int u, int par) {

    up[u][0] = par;
    for (int i = 1; i < 20; i++) {

        int v = up[u][i - 1];
        if (v != -1) up[u][i] = up[v][i - 1];
    }
    for (auto &v: adj[u]) {

        if (v == par) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int lift(int u, int k) {

    int ances = u;
    for (int i = 0; i < 20 && ances != -1; i++) {

        if (k & (1 << i)) ances = up[ances][i];
    }
    return ances;
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

void testcase() {

    int n, q;
    cin >> n >> q;
    
    adj.assign(n, vector<int>());
    up.assign(n, vector<int>(20, -1));
    for (int i = 0; i < n - 1; i++) {
    
       int u, v;
       cin >> u >> v;
       u--, v--;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    dep.assign(n, 0);
    dfs(0, -1);
    while (q--) {

        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << dep[u] + dep[v] - 2 * dep[lca(u, v)] << '\n';
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
