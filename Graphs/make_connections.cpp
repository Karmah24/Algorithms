#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> par, rank;
public:
    int clusters;
    UnionFind(int n) {
        clusters = n;
        par = vector<int>(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++) par[i] = i;
    }
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    void _union(int x, int y) {

        int x_root = find(x), y_root = find(y);
        if (x_root == y_root) return;
        clusters--;
        if (rank[x_root] <= rank[y_root]) {
            par[x_root] = y_root;
            if (rank[x_root] == rank[y_root]) rank[y_root]++;
        }
        else {
            par[y_root] = x_root;
        }
    }
};

class Solution {
    pair<int, int> dfs(int u, vector<int> adj[], vector<bool> &vis) {
        
        vis[u] = 1;
        int V = 1, E = adj[u].size();
        for (int v: adj[u]) {
            if (vis[v]) continue;
            auto [V1, E1] = dfs(v, adj, vis);
            V += V1, E += E1;
        }
        return {V, E};
    }
public:
    int makeConnected1(int n, vector<vector<int>> &connections) {
        
        vector<int> adj[n];
        for (auto ed: connections) {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        vector<bool> vis(n, 0);
        int count = 0, extraEdges = 0;
        for (int u = 0; u < n; u++) {
            
            if (!vis[u]) {
                count++;
                auto [v, e] = dfs(u, adj, vis);
                extraEdges += (e / 2) - (v - 1);
            }
        }
        if (extraEdges < count - 1) return -1;
        return count - 1;
    }

    int makeConnected(int n, vector<vector<int>> &connections) {

        if (connections.size() < n - 1) return -1;
        UnionFind uf(n);
        for (auto connection: connections) {
            uf._union(connection[0], connection[1]);
        }
        return uf.clusters - 1;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        arr[i].push_back(x);
        arr[i].push_back(y);
    }
    Solution obj;
    cout << obj.makeConnected(n, arr);
}