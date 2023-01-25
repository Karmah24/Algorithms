#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

int n;
vector<vector<int>> adj;

pair<int, int> dfs(int u, int par) {

    int white = 1, black = 1;
    for (auto &v: adj[u]) {
        if (v == par) continue;
        auto sub = dfs(v, u);
        white *= (sub.first + sub.second) % MOD;
        black *= (sub.first);
        white %= MOD, black %= MOD;
    }
    return {white, black};
}

void testcase() {

    cin >> n;
    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto p = dfs(0, -1);
    int res = (p.first + p.second) % MOD;
    cout << res;
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
