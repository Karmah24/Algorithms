#include <bits/stdc++.h>
using namespace std;

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
        first.resize(n);
        dep.clear();
        eulerTour.clear();
        dfs(adj, root);
        build_spt(dep);
    }
    void dfs(vector<vector<int>> &adj, int u = 0, int par = -1, int d = 0) {

        first[u] = eulerTour.size();
        eulerTour.push_back(u);
        dep.push_back(d);

        for (int v: adj[u]) {
            if (v == par) continue;
            dfs(adj, v, u, d + 1);
            eulerTour.push_back(u);
            dep.push_back(d);
        }
    }
    int query(int u1, int u2) {
        int l = first[u1 - 1], r = first[u2 - 1];
        if (l > r) swap(l, r);
        return eulerTour[get_min(l, r, dep)] + 1;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {

        int n, q;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                int v;
                cin >> v;
                adj[i].push_back(v - 1);
                adj[v - 1].push_back(i);
            }
        }
        LCA lca(adj);
        cout << "Case " << t << ":" << '\n';
        cin >> q;
        while (q--) {
            int u1, u2;
            cin >> u1 >> u2;
            cout << lca.query(u1, u2) << '\n';
        }
    }
    return 0;
}
