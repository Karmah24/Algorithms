#include <bits/stdc++.h>
using namespace std;

#define ll long long
//=======================
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dis(n, vector<ll>(n, LLONG_MAX));
    for (int i = 0; i < n; i++) dis[i][i] = 0;
    while (m--) {

        int u, v, w;
        cin >> u >> v >> w;
        dis[u - 1][v - 1] = dis[v - 1][u - 1] = min(dis[u - 1][v - 1], (ll)w);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dis[i][k] == LLONG_MAX || dis[j][k] == LLONG_MAX) continue;
                dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[j][k]);
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        ll res = dis[a - 1][b - 1];
        if (res == LLONG_MAX) res = -1;
        cout << res << '\n';
    }
    return 0;
}