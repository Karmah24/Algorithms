#include <bits/stdc++.h>
using namespace std;

bool canFinish1(int n, vector<vector<int>> prereqs) {
    
    vector<int> adj[n];
    vector<int> inDegree(n, 0);
    for (auto ed: prereqs) {
        adj[ed[0]].push_back(ed[1]);
        inDegree[ed[1]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) if (inDegree[i] == 0) q.push(i);
    int vis = 0;

    while (!q.empty()) {

        int u = q.front(); q.pop();
        vis++;
        for (int v: adj[u]) {
            if (--inDegree[v] == 0) q.push(v);
        }
    }
    return vis == n;
}
bool isCycle(int u, vector<int> adj[], bool vis[], unordered_set<int> &path) {

    vis[u] = 1;
    path.insert(u);

    for (int v: adj[u]) {
        if (path.count(v)) return 1;
        if (!vis[v] && isCycle(v, adj, vis, path)) return 1;
    }
    path.erase(u);
    return 0;
}
bool canFinish(int n, vector<vector<int>> prereqs) {
    
    vector<int> adj[n];
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    unordered_set<int> path;

    for (int u = 0; u < n; u++) {
        if (!vis[u] && isCycle(u, adj, vis, path)) return 0;
    }
    return 1;
}