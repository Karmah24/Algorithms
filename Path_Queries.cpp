#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
//=======================



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> val(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    return 0;
}