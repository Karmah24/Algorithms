#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e15;
const int N = 1e5 + 5;
//================================================================

vector<vector<pair<int, int>>> adj;
vector<int> dis;
vector<bool> neg_cycle;

class DSU {
public:
    vector<int> par, rank;
    DSU(int n): par(n), rank(n, 0) {
        for (int i = 0; i < n; i++) par[i] = i;
    }
    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    int merge(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return y;
        if (rank[x] > rank[y]) swap(x, y);
        par[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
        return y;
    }
};

void bfs(int src) {

    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty()) {

        int u = q.front(); q.pop();
        for (auto &[v, w]: adj[u]) {
            if (dis[v] == INF) {
                dis[v] = dis[u] + w;
                q.push(v);
            }
            else if (dis[v] != dis[u] + w) neg_cycle[src] = 1;
        }
    }
}

void testcase() {

    int n, m, q;
    cin >> n >> m >> q;

    adj.assign(n, vector<pair<int, int>>());
    DSU dsu(n);
    for (int i = 0; i < m; i++) {

        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        dsu.merge(u, v);
        adj[u].push_back({v, w});
        adj[v].push_back({u, -w});
    }
    dis.assign(n, INF);
    neg_cycle.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (dsu.par[i] != i) continue;
        bfs(i);
    }
    while (q--) {

        int x, y;
        cin >> x >> y;
        x--, y--;
        if (dsu.find(x) != dsu.find(y)) cout << "nan";
        else if (neg_cycle[dsu.find(x)]) cout << "inf";
        else cout << dis[y] - dis[x];
        cout << '\n';
    }
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
