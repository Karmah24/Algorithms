#include <bits/stdc++.h>
using namespace std;
#define int long long
//=======================
class DSU {
public:
    int cnt;
    vector<int> par, rank;
    DSU(int n): par(n), rank(n, 1), cnt(n) {
        for (int i = 0; i < n; i++) par[i] = i;
    }
    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    int merge(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return y;
        cnt--;
        if (rank[x] > rank[y]) swap(x, y);
        par[x] = y;
        rank[y] += rank[x];
        return y;
    }
};
void solve() {

    int n, d, u, v, xtra = 0;
    cin >> n >> d;
    DSU dsu(n);
    while (d--) {
        cin >> u >> v;
        --u, --v;
        if (dsu.find(u) == dsu.find(v)) xtra++;
        dsu.merge(u, v);
        vector<bool> vis(n, false);
        vector<int> set_sizes;
        for (int i = 0; i < n; i++) {
            int p = dsu.find(i);
            if (!vis[p]) set_sizes.push_back(dsu.rank[p]);
            vis[p] = true;
        }
        sort(set_sizes.rbegin(), set_sizes.rend());
        int res = 0;
        for (int i = 0; i < xtra + 1; i++) {
            res += set_sizes[i];
        }
        cout << res - 1 << '\n';
    }
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}