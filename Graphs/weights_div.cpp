#include<bits/stdc++.h>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define ll long long
typedef vector<int>	    vi;
typedef pair<int, int>	pii;
typedef vector<pii>     vpii;
void ipgraph(int n, int m);
void tree_dfs(int u, int par);
const int N = 3e5, M = N;
//=======================

vpii graph[N];
vi w, cnt;

ll get_diff(int i) {
   return (ll)(w[i] - w[i] / 2) * (ll)cnt[i];
}

void solve(int n, ll s) {
    tree_dfs(0, -1);
    ll cur = 0;
    set<pair<ll, int>> st;
    loop (i, n - 1) {
        cur += w[i] * cnt[i];
        st.insert({get_diff(i), i});
    }
    int res = 0;
    while (cur > s) {
        int id = st.rbegin()->second;
        cur -= st.rbegin()->first;
        st.erase(prev(st.end()));
        w[id] /= 2;
        st.insert({get_diff(id), id});
        res++;
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n; ll s;
        cin >> n >> s;
        w = cnt = vi(n - 1);
        ipgraph(n, n - 1);
        solve(n, s);
        for (auto& v : graph) 
            v.clear();
    }
}

void ipgraph(int n, int m){
    int u, v, _w;
    loop (i, n - 1) {
        cin >> u >> v >> _w;
        u--, v--;
        w[i] = _w;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }
}
void tree_dfs(int u, int p){
    if (graph[u].size() == 1) cnt[p] = 1;

    for (auto [to, id] : graph[u]){
        if (id == p) continue;
        tree_dfs(to, id);
        if (p != -1)
            cnt[p] += cnt[id];
    }
}