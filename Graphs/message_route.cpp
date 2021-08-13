#include <bits/stdc++.h>
using namespace std;

void solve(int st, int fin, int n, vector<int> adj[]) {
    
    vector<int> par(n);
    queue<int> q;
    vector<bool> vis(n, false); 
    q.push(st);
    vis[st] = true;
    par[st] = -1;
    bool pathExists = false;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        for (int v: adj[u]) {
            if (vis[v]) continue;
            par[v] = u;
            vis[v] = true;
            q.push(v);
            if (v == fin) {
                pathExists = true;
                break;
            }
        }
        if (pathExists) break;
    }
    if (!pathExists) {
        cout << "IMPOSSIBLE";
        return;
    }
    int u = fin;
    vector<int> path;
    while (u != -1) {
        path.push_back(u + 1);
        u = par[u];
    }
    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << ' ';
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
    solve(0, n - 1, n, adj);
    return 0;
}