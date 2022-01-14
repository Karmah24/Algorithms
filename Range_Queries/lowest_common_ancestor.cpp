#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
//=======================

class Sparse {
    vector<vector<int>> dp;
public:
    Sparse(vector<int> &arr) {

        int m = arr.size();
        int n = floor(log2(m)) + 1;
        dp.assign(n, vector<int>(m));

        for (int i = 0; i < m; i++) {
            dp[0][i] = arr[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int getMin(int l, int r) {
        int p = floor(log2(r - l + 1));
        int k = 1 << p;
        return min(dp[p][l], dp[p][r - k + 1]);
    }
};
class LCA {
    int n;
    vector<int> eulerTour, height, first;
    Sparse *sparse;
public:
    LCA(vector<vector<int>> &adj, int root = 0) {

        n = adj.size();
        height.resize(n);
        first.resize(n);
        eulerTour.reserve(2 * n);
        dfs(adj, root);
        sparse = new Sparse(eulerTour);
    }
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
    int query(int u1, int u2) {
        int l = first[u1 - 1], r = first[u2 - 1];
        if (l > r) swap(l, r);
        return sparse->getMin(l, r) + 1;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, q;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    LCA lca(adj);
    cin >> q;
    while (q--) {

        int r, u, v;
        cin >> r >> u >> v;
        int a = lca.query(u, v);
        int b = lca.query(r, u);
        int c = lca.query(r, v);
        if (a == b) cout << c << ln;
        else if (b == c) cout << a << ln;
        else cout << b << ln;
    }
    return 0;
}