#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dis(n, vector<int>(n, INF));
    vector<vector<int>> cost(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        dis[i][i] = 0;
        cost[i][i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        string v;
        cin >> v;
        for (int j = 0; j < n; j++) {
            if (v[j] == 'Y') {
                dis[i][j] = 1;
                cost[i][j] = a[i] + a[j];
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dis[i][k] == INF || dis[k][j] == INF) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][k] == -1 || cost[k][j] == -1) continue;
                if (dis[i][j] == dis[i][k] + dis[k][j]) {
                    cost[i][j] = max(cost[i][j], cost[i][k] + cost[k][j] - a[k]);
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (dis[u][v] == INF) cout << "Impossible\n";
        else cout << dis[u][v] << " " << cost[u][v] << '\n';
    }
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
