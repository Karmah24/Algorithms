#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================
unordered_map<string, int> mp;
vector<vector<int>> adj;

void dfs(int u, int par, int w) {
    mp[to_string(par) + " " + to_string(u)] = w;
    for (int v: adj[u]) {
        if (v == par) continue;
        dfs(v, u, 5 - w);
    }
}
void solve() {

    int n, u, v;
    cin >> n;
    mp.clear();
    adj.assign(n, vector<int>());
    bool excessDegree = false;
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++) {
        cin >> u  >> v;
        u--, v--;
        edges.push_back({u, v});
        adj[u].push_back(v), adj[v].push_back(u);
        if (adj[u].size() > 2 || adj[v].size() > 2) excessDegree = true;
    }
    if (excessDegree) {
        cout << -1;
        return;
    }
    dfs(adj[0][0], 0, 2);
    if (adj[0].size() > 1) dfs(adj[0][1], 0, 3);
    for (auto &p: edges) {
        string s1 = to_string(p.first) + " " + to_string(p.second);
        if (mp.count(s1)) cout << mp[s1] << " ";
        else {
            string s2 = to_string(p.second) + " " + to_string(p.first);
            cout << mp[s2] << " ";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}