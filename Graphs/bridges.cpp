#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> low, dep;
    vector<vector<int>> bridges;

    void dfs(int u, int par, vector<int> adj[], int d = 0) {

        dep[u] = low[u] = d;
        for (int v: adj[u]) {

            if (low[v] != -1 && v == par) continue;
            if (low[v] == -1) dfs(v, u, adj, d + 1);
            if (low[v] > dep[u]) bridges.push_back({u, v});
            low[u] = min(low[u], low[v]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        low = vector<int>(n, -1);
        dep = vector<int>(n, -1);
        bridges.clear();
        vector<int> adj[n];

        for (auto &connection: connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        for (int u = 0; u < n; u++) {
            if (low[u] == -1) dfs(u, -1, adj);
        }
        return bridges;
    }
};
