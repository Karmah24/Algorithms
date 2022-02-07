#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================
vector<vector<pair<int, bool>>> adj;
vector<bool> vis, is_c;

int dfs(int u, int &n) {
    n++;
    vis[u] = 1;
    int c = is_c[u];
    for (auto &[v, w]: adj[u]) {
        if (vis[v]) {
            if (is_c[v] == !(is_c[u] ^ w)) continue;
            return -1;
        }
        is_c[v] = !(is_c[u] ^ w);
        int x = dfs(v, n);
        if (x == -1) return -1;
        c += x;
    }
    return c;
}
int solve() {
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<pair<int, bool>>());
    vis = is_c = vector<bool>(n, 0);
    while (m--) {
        int u, v, w;
        string s;
        cin >> u >> v >> s;
        --u, --v;
        adj[u].push_back({v, w = s == "crewmate"});
        adj[v].push_back({u, w});
    }
    int res = 0;
    for (int u = 0; u < n; u++) {
        if (vis[u]) continue;
        int s = 0;
        int x = dfs(u, s);
        if (x == -1) return -1;
        res += max(x, s - x);
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}