#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

int n, a, b;
vector<vector<pair<int, int>>> adj;
vector<int> par, xxora, xxorb;

void dfs(int u, vector<int> &xxor, bool f = 0) {

    if (f && u == b) return;
    for (auto &[v, w]: adj[u]) {

        if (v == par[u]) continue;
        par[v] = u;
        xxor[v] = xxor[u] ^ w;
        dfs(v, xxor, f);
    }
}

void testcase() {

    cin >> n >> a >> b;
    a--, b--;
    
    adj.assign(n, vector<pair<int, int>>());
    xxorb.assign(n, 0);
    xxora.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {
    
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    par.assign(n, -1);
    dfs(b, xxorb);
    par.assign(n, -1);
    dfs(a, xxora, 1);
    map<int, int> cnt;
    for (auto &e: xxorb) cnt[e]++;
    bool ok = cnt[0] > 1;
    xxora[b] = -1;
    xxorb[a] = -2;
    for (auto &e: xxora) {
        if (e != 0 && cnt[e] > 0) ok = 1;
    }
    cout << (ok ? "YES" : "NO");
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
