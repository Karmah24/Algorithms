#include <bits/stdc++.h>
using namespace std;
//================================================================

int n;
vector<vector<int>> adj;
vector<int> par, dep;

void dfs(int u) {

    for (auto &v: adj[u]) {

        if (v == par[u]) continue;
        par[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

void testcase() {

    cin >> n;

    adj.assign(n, vector<int>());
    par.assign(n, -1);
    dep.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {
       int u, v;
       cin >> u >> v;
       u--, v--;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    dfs(0);
    // one end of diameter
    int d1 = max_element(dep.begin(), dep.end()) - dep.begin();
    par.assign(n, -1);
    dep.assign(n, 0);
    dfs(d1);
    int diameter = *max_element(dep.begin(), dep.end());
    cout << diameter;
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
