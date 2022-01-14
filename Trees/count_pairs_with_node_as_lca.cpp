#include <bits/stdc++.h>
using namespace std;

int x, x_tot;
vector<int> sub;

int dfs(vector<int> adj[], int u = 0, int par = -1) {

    int tot = 0;
    for (int &v: adj[u]) {
        if (v == par) continue;
        int s = dfs(adj, v, u);
        tot += s;
        if (u == x) sub.push_back(s);
    }
    if (u == x) x_tot = tot;
    return tot + 1;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n >> x;
    x--;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    sub.clear();
    dfs(adj);
    long long res = x_tot;
    for (int &e: sub) {
        res += (x_tot - e) * e;
        x_tot -= e;
    }
    cout << res;
    return 0;
}