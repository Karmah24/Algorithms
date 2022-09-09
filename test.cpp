#ifdef DEBUG
#include "debug.hpp"
#else
#pragma GCC optimize("Ofast")
#define trace(...)
#include <bits/stdc++.h>
#define endl '\n'
#endif

using namespace std;
using adj_list = vector<vector<int>>;

const int MOD = 1'000'000'007;

struct sparse_table {
    vector<vector<int>> st;

    sparse_table() {}

    sparse_table(int n, vector<int> const& parent)
        : st(n, vector<int>(__lg(n) + 1)) {
        int k = __lg(n);
        for (int i = 0; i < n; ++i) {
            st[i][0] = parent[i];
        }
        for (int j = 1; j <= k; ++j) {
            for (int i = 0; i < n; ++i) {
                st[i][j] = st[i][j - 1] == -1 ? -1 : st[st[i][j - 1]][j - 1];
            }
        }
    }

    int ancestor(int u, int n) {
        for (; n; n -= n & -n) {
            if (u == -1) return -1;
            int k = __builtin_ctz(n & -n);
            u = st[u][k];
        }
        return u;
    }
};

int n, m;
adj_list g;

vector<int> parent;
vector<int> depth;
vector<bool> in_cycle;
vector<int> cycle;

// Return true if there is no back-edge down from u
bool dfs1(int u) {
    bool b = true;
    for (int v : g[u]) {
        if (parent[v] == -1) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            if (dfs1(v) && in_cycle[v]) {
                cycle[u] = cycle[v];
                in_cycle[u] = true;
            }
        } 
        else if (parent[u] != v) {
            if (depth[u] > depth[v]) {
                // Back-edge up from u to v
                cycle[u] = v;
                in_cycle[u] = true;
            } 
            else {
                // Back-edge down from u to v
                b = false;
            }
        }
    }
    return b;
}

vector<int> cnt;

void dfs2(int u) {
    cnt[u] += in_cycle[u];
    for (int v : g[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        cnt[v] += cnt[u];
        dfs2(v);
    }
}

sparse_table st;

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);

    v = st.ancestor(v, depth[v] - depth[u]);

    if (u == v) return u;

    for (int i = __lg(depth[u]); i >= 0; --i) {
        int x = st.ancestor(u, 1 << i);
        int y = st.ancestor(v, 1 << i);
        if (x != y) {
            u = x;
            v = y;
        }
    }
    return parent[u];
}

int modexp(long long b, int e) {
    long long ans = 1;
    for (; e; e >>= 1) {
        if (e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    g = adj_list(n);
    //ipg
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Find cycles
    parent = vector<int>(n, -1);
    depth = vector<int>(n);
    in_cycle = vector<bool>(n, false);
    cycle = vector<int>(n);
    iota(cycle.begin(), cycle.end(), 0);
    parent[0] = 0;
    depth[0] = 0;
    dfs1(0);

    // Compress cycles
    for (int u = 0; u < n; ++u) {
        if (cycle[u] == u) continue;
        g[cycle[u]].insert(g[cycle[u]].end(), g[u].begin(), g[u].end());
        g[u].clear();
    }

    for (int u = 0; u < n; ++u) {
        transform(g[u].begin(), g[u].end(), g[u].begin(),
                  [](int k) { return cycle[k]; });
        g[u].erase(remove(g[u].begin(), g[u].end(), u), g[u].end());
        sort(g[u].begin(), g[u].end());
        g[u].erase(unique(g[u].begin(), g[u].end()), g[u].end());
    }

    // Precompute prefix sums and LCA
    parent = vector<int>(n, -1);
    depth = vector<int>(n);
    cnt = vector<int>(n, 0);
    parent[0] = 0;
    depth[0] = 0;
    dfs2(0);

    st = sparse_table(n, parent);

    // Answer queries
    int k;
    cin >> k;

    while (k--) {
        int x, y;
        cin >> x >> y;
        x = cycle[x - 1];
        y = cycle[y - 1];
        int w = lca(x, y);
        int e = cnt[x] + cnt[y] - 2 * cnt[w] + in_cycle[w];
        cout << modexp(2, e) << endl;
    }

    return 0;
}
