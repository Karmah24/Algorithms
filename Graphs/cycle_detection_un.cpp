#include<bits/stdc++.h>

using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
#define pb push_back
typedef vector<int>	    vi;
void ipgraph(int n, int m);
void dfs(int s, int par);
const int N = 3e5, M = N;
//=======================

bool res;
vi graph[N];
bool vis[N] = {};

void solve() {
    res = 0;
    int n, m;
    cin >> n >> m;
    ipgraph(n, m);

    fori (i, n) {
        if (!vis[i])
            dfs(i, -1);
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
        for (auto& v : graph) 
            v.clear();
        for (auto& v : vis)
                v = false;
    }

    return 0;
}

void ipgraph(int n, int m){
    int u, v;
    while (m--) {
        cin >> u >> v;
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);  
    }
}


void dfs(int s, int par) {
    if (res == 1)
        return;
    // set.insert(s);
    vis[s] = true;
    for (auto v : graph[s]) {
        if (vis[v] && v != par) {    // if (vis[v] && set.find(e) != set.end())
            res = 1;
            return;
        }
        else if (!vis[v])
            dfs(v, s);
    }
    // set.erase(set.find(s));
}