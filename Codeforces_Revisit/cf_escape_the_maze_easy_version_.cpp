#include <bits/stdc++.h>
using namespace std;
#define int long long
//=======================
vector<int> lvl;
vector<vector<int>> adj;
vector<bool> vis;
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v: adj[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            lvl[v] = lvl[u] + 1;
            q.push(v);
        }
    }
}
bool dfs(int u = 0, int par = -1, int ttime = 0) {
    if (adj[u].size() == 1 && u != 0 && lvl[u] > ttime) return true;
    for (auto &v: adj[u]) {
        if (v == par || lvl[v] <= ttime) continue;
        if (dfs(v, u, ttime + 1)) return true;
    }
    return false;
}
int solve() {

    int n, k, u, v;
    cin >> n >> k;
    adj.assign(n, vector<int>());
    lvl.assign(n, INT_MAX);
    vis.assign(n, false);
    while (k--) {
        cin >> u;
        --u;
        lvl[u] = 0;
        vis[u] = true;
        q.push(u);
    }
    while (--n) {
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    return dfs();
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}