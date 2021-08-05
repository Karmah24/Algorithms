#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
//=======================

class Sparse {
    vector<vector<int>> dpm, dpM;
public:
    Sparse(vector<int> &arr, unordered_map<string, int> &edges) {

        int m = arr.size();
        int n = floor(log2(m)) + 1;
        dpm.assign(n, vector<int>(m - 1));
        dpM.assign(n, vector<int>(m - 1));

        for (int i = 0; i < m - 1; i++) {
            int u = arr[i], v = arr[i + 1];
            string _u = to_string(u), _v = to_string(v);
            dpm[0][i] = dpM[0][i] = edges[_u + " " + _v];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dpm[i][j] = min(dpm[i - 1][j], dpm[i - 1][j + (1 << (i - 1))]);
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dpM[i][j] = max(dpM[i - 1][j], dpM[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int getMin(int l, int r) {
        r--;
        int p = floor(log2(r - l + 1));
        int k = 1 << p;
        return min(dpm[p][l], dpm[p][r - k + 1]);
    }
    int getMax(int l, int r) {
        r--;
        int p = floor(log2(r - l + 1));
        int k = 1 << p;
        return max(dpM[p][l], dpM[p][r - k + 1]);
    }
};
class LCA {
    int n;
    vector<int> eulerTour, height, first;
    Sparse *spt = nullptr;

    void dfs(vector<vector<int>> &adj, int u = 0, int par = -1, int h = 0) {

        height[u] = h;
        first[u] = eulerTour.size();
        eulerTour.push_back(u);

        for (int v: adj[u]) {
            if (v == par) continue;
            dfs(adj, v, u, h + 1);
            eulerTour.push_back(u);
        }
    }
public:
    LCA(vector<vector<int>> &adj, unordered_map<string, int> &edges, int root = 0) {

        n = adj.size();
        height.resize(n);
        first.resize(n);
        eulerTour.reserve(2 * n);
        dfs(adj, root);
        spt = new Sparse(eulerTour, edges);
    }
    pair<int, int> query(int u1, int u2) {
        int l = first[u1 - 1], r = first[u2 - 1];
        if (l > r) swap(l, r);
        return {spt->getMin(l, r), spt->getMax(l, r)};
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n;
    unordered_map<string, int> edges;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        string _u = to_string(u), _v = to_string(v);
        edges[_u + " " + _v] = w;
        edges[_v + " " + _u] = w;
    }
    LCA lca(adj, edges);
    cin >> q;
    while (q--) {

        int u, v;
        cin >> u >> v;
        auto res = lca.query(u, v);
        cout << res.first << " " << res.second << ln;
    }
    return 0;
}