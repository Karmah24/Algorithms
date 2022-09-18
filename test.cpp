#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================
 
vector<vector<int>> adj, up;
vector<int> dep;
 
void dfs(int u, int par) {
 
    up[u][0] = par;
    for (int i = 1; i < 20; i++) {
 
        int v = up[u][i - 1];
        if (v != -1) up[u][i] = up[v][i - 1];
    }
    for (auto &v: adj[u]) {
 
        if (v == par) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}
 
int lift(int u, int k) {
 
    int ances = u;
    for (int i = 0; i < 20 && ances != -1; i++) {
 
        if (k & (1 << i)) ances = up[ances][i];
    }
    return ances;
}
 
int lca(int u, int v) {
 
    if (dep[u] < dep[v]) swap(u, v);
 
    lift(u, dep[u] - dep[v]);
    if (u == v) return u;
 
    for (int i = 19; i >= 0; i--) {
 
        if (up[u][i] != up[v][i]) {
 
            u = up[u][i], v = up[v][i];
        }
    }
    return up[u][0];
}