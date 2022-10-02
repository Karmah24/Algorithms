#include <bits/stdc++.h>
using namespace std;
//================================================================

int n, timer;
vector<vector<int>> adj;
vector<int> par, dep, tin, tout;

void dfs(int u) {

    tin[u] = timer++;
    for (auto &v: adj[u]) {

        if (v == par[u]) continue;
        par[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
    tout[u] = timer++;
}

bool is_ances(int u, int v) {

    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void testcase() {

    int m;
    cin >> n >> m;
    
    timer = 0;
    adj.assign(n, vector<int>());
    par.assign(n, -1);
    for (int i = 0; i < n - 1; i++) {
    
       int u, v;
       cin >> u >> v;
       u--, v--;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    dep.assign(n, 0);
    tin.resize(n);
    tout.resize(n);
    dfs(0);

    for (int i = 0; i < m; i++) {

        int k;
        cin >> k;
        vector<int> a(k);
        for (auto &u: a)  {

            cin >> u;
            u--;
        }
        int last = *max_element(a.begin(), a.end(), [&](int u, int v) {
            return dep[u] < dep[v];
        });
        for (auto &u: a) {

            if (par[u] != -1) u = par[u];
        }
        bool res = true;
        for (auto &u: a) res &= is_ances(u, last);
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
