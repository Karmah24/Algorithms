#include <bits/stdc++.h>
using namespace std;
//=======================

int xo, cnt;
vector<int> arr;
vector<vector<int>> adj;

int dfs(int u, int par = -1) {
    int sub = arr[u];
    for (int v: adj[u]) if (v != par) sub ^= dfs(v, u);
    if (sub == xo) {
        sub = 0;
        cnt++;
    }
    return sub;
}
bool solve() {
    int n, k;
    cin >> n >> k;
    arr.resize(n);
    adj.assign(n, vector<int>());
    xo = cnt = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        xo ^= arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    if (xo == 0) return true;
    dfs(0);
    return cnt >= 2 && k >= 3;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        if (solve()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}