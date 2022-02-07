#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================

int solve() {
    int n, k;
    cin >> n >> k;
    vector<unordered_set<int>> adj(n);
    vector<int> leaf_dis(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[--u].insert(--v);
        adj[v].insert(u);
    }
    if (k >= (n + 1) / 2) return 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) q.push(i);
    }
    while (k-- && !q.empty()) {
        int s = q.size();
        n -= s;
        while (s--) {
            int u = q.front();
            q.pop();
            for (auto &v: adj[u]) {
                adj[v].erase(u);
                if (adj[v].size() == 1) q.push(v);
            }
        }
    }
    return n;
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
        cout << solve() << '\n';
    }
    return 0;
}