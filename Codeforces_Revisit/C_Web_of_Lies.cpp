#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {
    
    int n, m;
    cin >> n >> m;
    vector<int> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        adj[u]++;
    }
    int res = 0;
    for (auto &e: adj)  {
        if (e == 0) res++;
    }
    int q;
    cin >> q;
    while (q--) {
        int qt;
        cin >> qt;
        if (qt == 3) cout << res << '\n';
        else {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);
            if (qt == 1) {
                if (adj[u] == 0) res--;
                adj[u]++;
            }
            else {
                adj[u]--;
                if (adj[u] == 0) res++;
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}