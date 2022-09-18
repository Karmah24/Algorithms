// remove an edge to make a graph(forest) bipartite
// find all such edges
// if all scc are bipartite any edge can be picked
// if more than one component is bad (non-bipartite) no edge can be picked
// within a bad scc, if only one contradictory back edge is present it can be picked
// and any span edge with all contradictory back edges passing over can be picked
// in the second case the spaning tree breaks into 2 and color of one can be switched

#include <bits/stdc++.h>
using namespace std;
//================================================================

vector<vector<pair<int, int>>> adj;
int bad_edges;
vector<int> dp1, dp2; // dp1 - total back edges, dp2 - bad back edges
vector<int> dep, par;

void dfs1(int u) {

    for (auto &[v, idx]: adj[u]) {

        if (v == par[u]) continue;
        if (par[v] == -1) { // span edge

            par[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            dp1[u] += dp1[v];
            dp2[u] += dp2[v];
        }
        else if (dep[u] > dep[v]) { // back edge up from u to v

            dp1[u]++;
            if (!((dep[u] ^ dep[v]) & 1)) {

                bad_edges++;
                dp2[u]++;
            }
        }
        else { // back edge down from u to v

            dp1[u]--;
            if (!((dep[u] ^ dep[v]) & 1)) dp2[u]--;
        }
    }
}

vector<int> res;

void dfs2(int u) {

    for (auto &[v, idx]: adj[u]) {

        if (v == par[u]) {

            if (dp1[u] == bad_edges && dp2[u] == bad_edges) {

                res.push_back(idx);
            }
        }
        else if (par[v] == u) { // span edge

            dfs2(v);
        }
        else if (dep[u] > dep[v]) { // back edge up from u to v

            if (bad_edges == 1 && !((dep[u] ^ dep[v]) & 1)) {

                res.push_back(idx);
            }
        }
    }
}

void testcase() {

	int n, m;
    cin >> n >> m;

    adj.assign(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
       int u, v;
       cin >> u >> v;
       u--, v--;
       adj[u].push_back({v, i});
       adj[v].push_back({u, i});
    }

    dp1.assign(n, 0);
    dp2.assign(n, 0);
    dep.assign(n, 0);
    par.assign(n, -1);
    int bad_comps = 0;

    for (int u = 0; u < n; u++) {

        if (par[u] != -1) continue;

        bad_edges = 0;
        par[u] = u;
        dfs1(u);
        if (bad_edges == 0) continue;

        bad_comps++;
        dfs2(u);
    }
    if (bad_comps == 0) {

        cout << m << '\n';
        for (int i = 1; i <= m; i++) cout << i << " ";
    }
    else if (bad_comps > 1) {

        cout << "0\n";
    }
    else {

        sort(res.begin(), res.end());
        cout << res.size() << '\n';
        for (auto &e: res) cout << e + 1 << " ";
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
		// cout << '\n';
	}
	return 0;
}
