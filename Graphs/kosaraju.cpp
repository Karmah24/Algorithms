#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define pb push_back
typedef vector<int>	    vi;

void ipgraph(int n, int m);
void dfs(vi g[], int s);
const int N = 5, M = N;
//=======================

vi graph[N];
vi tp[N];
stack<int> st;
bool vis[N] = {};

void transpose(vi graph[], vi tp[], int n) {
    loop (i, n) {
        for (int v : graph[i])
            tp[v].pb(i);
    }
}
void solve() {
    int n, m, res = 0;
    cin >> n >> m;
    ipgraph(n, m);

    loop (i, n) {
        if (!vis[i])
            dfs(graph, i);
    }
    for (bool& e : vis)
        e = 0;
    transpose(graph, tp, n);

    while (st.size()) {
        if (!vis[st.top()]) {
            res++;
            dfs(tp, st.top());
        }
        st.pop();
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
        for (auto& v : tp) 
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
        graph[u].pb(v);
    }
}

void dfs(vi g[], int s) {
    vis[s] = true;
    for (auto v : g[s]) {
        if (vis[v]) continue;
        dfs(g, v);
    }
    st.push(s);
}