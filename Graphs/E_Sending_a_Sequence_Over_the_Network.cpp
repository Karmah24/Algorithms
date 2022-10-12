#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

int n;
vector<int> a;
vector<vector<int>> adj;
vector<int> vis;

bool dfs(int u) {

    if (u == n + 1) return 1;
    vis[u] = 1;
    for (auto &v: adj[u]) {

        if (!vis[v] && dfs(v)) return 1;
    }
    return 0;
}

void testcase() {

    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> a[i];

    adj.assign(n + 2, vector<int>());
    for (int i = 1; i < n + 1; i++) {

        if (i + a[i] + 1 <= n + 1) adj[i].push_back(i + a[i] + 1);
        if (i - a[i] > 0) adj[i - a[i]].push_back(i + 1);
    }
    vis.assign(n + 2, 0);
    bool ok = dfs(1);
    if (ok) cout << "YES";
    else cout << "NO";
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
