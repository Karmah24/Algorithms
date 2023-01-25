#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

vector<vector<int>> adj;
vector<int> par;

void dfs(int u) {

    for (auto &v: adj[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        dfs(v);
    }
}

void testcase() {

    int n, q;
    cin >> n;

    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {

        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par.assign(n, -1);
    dfs(0);
    vector<int> val(n, 0), children(n);
    children[0] = adj[0].size();
    for (int i = 1; i < n; i++) children[i] = adj[i].size() - 1;
    int cnt_zero = n - 1;
    cin >> q;
    while (q--) {
        int t, u;
        cin >> t;
        if (t == 1) {
            cin >> u;
            u--;
            if (val[u] == 1 || children[u] != 0) continue;
            val[u] = 1;
            if (u != 0) {
                cnt_zero--;
                children[par[u]]--;
            }
        }
        else {
            cout << (val[0] == 1 ? n - 1 : cnt_zero) << '\n';
        }
    }
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
