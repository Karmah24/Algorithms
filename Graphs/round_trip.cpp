#include <bits/stdc++.h>
using namespace std;

int st, fin;

bool dfs(int u, vector<int> adj[], vector<bool> &vis, vector<int> &par) {
    
    vis[u] = true;
    for (int v: adj[u]) {

        if (v == par[u]) continue;
        par[v] = u;
        if (vis[v]) {
            st = v, fin = u;
            return true;
        }
        if (dfs(v, adj, vis, par)) return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<int> par(n);
    vector<bool> vis(n, false);
    st = fin = -1;
    bool isCyclic = false;
    for (int i = 0; i < n; i++) {
        par[i] = -1;
        if (!vis[i] && dfs(i, adj, vis, par)) {
            isCyclic = true;
            break;
        }
    }
    if (!isCyclic) cout << "IMPOSSIBLE";
    else {
        vector<int> tour = {fin + 1};
        int u = par[fin];
        while (u != fin) {
            tour.push_back(u + 1);
            u = par[u];
        }
        tour.push_back(fin + 1);
        cout << tour.size() << '\n';
        for (int &e: tour) cout << e << ' ';
    }
    return 0;
}