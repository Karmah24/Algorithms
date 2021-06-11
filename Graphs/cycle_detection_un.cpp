#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> graph;

    bool dfs(int u, int par, vector<bool> &vis) {
        vis[u] = true;
        for (int v: graph[u]) {
            if (vis[v] && v != par) return 1;
            else if (!vis[v] && dfs(v, u, vis)) return 1;
        }
        return 0;
    }
public:
    bool detectCycle(int n, vector<vector<int>> &edges) {

        graph = vector<vector<int>>(n);

        for (int i = 0; i < edges.size(); i++) {

            graph[edges[i][0] - 1].push_back(edges[i][1] - 1);
            graph[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }
        vector<bool> vis(n, false);
        for (int i = 0; i < edges.size(); i++) {
            if (!vis[i] && dfs(i, -1, vis)) return 1;
        }
        return 0;
    }
};