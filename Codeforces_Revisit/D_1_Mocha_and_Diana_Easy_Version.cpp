#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

class DSU {
public:
    int cnt;
    vector<int> par, rank;
    DSU(int n): par(n), rank(n, 0), cnt(n) {
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
        if (rank[x] == rank[y]) rank[y]++;
        return y;
    }
};

void solve() {
    
    int n, m1, m2, u, v;
    cin >> n >> m1 >> m2;
    DSU dsu1(n), dsu2(n);
    while (m1--) {
        cin >> u >> v;
        dsu1.merge(u - 1, v - 1);
    }
    while (m2--) {
        cin >> u >> v;
        dsu2.merge(u - 1, v - 1);
    }
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dsu1.find(i) != dsu1.find(j) && dsu2.find(i) != dsu2.find(j)) {
                res.push_back({i, j});
                dsu1.merge(i, j);
                dsu2.merge(i, j);
            }
        }
    }
    cout << res.size() << '\n';
    for (auto &[f, s]: res) {
        cout << f + 1<< " " << s + 1 << '\n';
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