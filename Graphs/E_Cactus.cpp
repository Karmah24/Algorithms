#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
ll mul(ll x, ll y) {return ((x % MOD) * (y % MOD)) % MOD;}
ll mpow(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) res = mul(res, x);
		x = mul(x, x);
		n >>= 1;
	}
	return res;
}

const int N = 25, M = 2e5;
int spt[N][M];
void build_spt(vector<int> &v) {
    int m = v.size();
    int n = floor(log2(m));
    auto cmp = [&](int i, int j) {
        return v[i] < v[j];
    };
    for (int i = 0; i < m; i++) spt[0][i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            spt[i][j] = min(spt[i - 1][j], spt[i - 1][j + (1 << (i - 1))], cmp);
        }
    }
}
int get_min(int l, int r, vector<int> &v) {
    int p = floor(log2(r - l + 1));
    int k = 1 << p;
    return min(spt[p][l], spt[p][r - k + 1], 
            [&](int i, int j) { return v[i] < v[j]; });
}

class LCA {
    int n;
    vector<int> eulerTour, dep, first;
public:
    LCA(vector<vector<int>> &adj, int root = 0) {

        n = adj.size();
        first.assign(n, -1);
        dep.clear();
        eulerTour.clear();
        dfs(adj, root);
        build_spt(dep);
    }
    void dfs(vector<vector<int>> &adj, int u = 0, int d = 0) {

        first[u] = eulerTour.size();
        eulerTour.push_back(u);
        dep.push_back(d);

        for (int v: adj[u]) {
            if (first[v] != -1) continue;
            dfs(adj, v, d + 1);
            eulerTour.push_back(u);
            dep.push_back(d);
        }
    }
    int query(int u1, int u2) {
        int l = first[u1], r = first[u2];
        if (l > r) swap(l, r);
        return eulerTour[get_min(l, r, dep)];
    }
};
//================================================================

vector<vector<int>> adj;
vector<int> dep, cycle, cnt;

// compressing cycles
void dfs1(int u, int par = -1, int d = 0) {

	dep[u] = d;
	for (auto &v: adj[u]) {

		if (v == par) continue;
		if (dep[v] == -1) { // span edge
			dfs1(v, u, d + 1);
		}
		else if (dep[u] > dep[v]) { // back edge
			cycle[u] = v;	
		}
		if (cycle[v] != v) {
			if (cycle[v] == u) cycle[u] = -1; // head of cycle
			else if (cycle[v] != -1) {
				cycle[u] = cycle[v];
			}
		}
	}
}

// count # of cycle heads from root to u
void dfs2(int u, int c = 0) {

	cnt[u] = c + (cycle[u] == -1);
	for (auto &v: adj[u]) {

		if (cnt[v] != -1) continue;
		dfs2(v, cnt[u]);
	}
}

void testcase() {

	int n, m;
	cin >> n >> m;

	adj.assign(n, vector<int>());
	for (int i = 0; i < m; i++) {
	   int u, v;
	   cin >> u >> v;
	   u--, v--;
	   adj[u].push_back(v);
	   adj[v].push_back(u);
	}

	// compressing cycles
	cycle.resize(n);
	for (int i = 0; i < n; i++) cycle[i] = i;
	dep.assign(n, -1);
	dfs1(0);

	// counting # cycles from root to a vertex
	cnt.assign(n, -1);
	dfs2(0);
	
	LCA lca(adj);

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		int ances = lca.query(u, v);

		cout << mpow(2, (cnt[u] + cnt[v] - 2 * cnt[ances]) + (cycle[ances] != ances)) << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("../input.txt", "r", stdin);
	  freopen("../output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		// cout << '\n';
	}
	return 0;
}
