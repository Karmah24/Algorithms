#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> adj[]) {
    
    vector<int> team(n, 0);
    queue<int> q;
    bool isBipartite = true;

    for (int i = 0; i < n; i++) {
        if (team[i] != 0) continue;
        team[i] = 1;
        q.push(i);
        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (int v: adj[u]) {
                if (team[v] == team[u]) {
                    isBipartite = false;
                    break;
                }
                if (team[v] == 0) {
                    team[v] = 3 - team[u];
                    q.push(v);
                }
            }
            if (!isBipartite) break;
        }
    }
    if (!isBipartite) {
        cout << "IMPOSSIBLE";
        return;
    }
    for (int &e: team) cout << e << ' ';
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
    solve(n, adj);
    return 0;
}