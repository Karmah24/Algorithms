#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int n;
vector<vector<tuple<int, int, int>>> adj(n);
vector<int> pfx_b, res;

void dfs(int u, int p = -1, int A = 0, int B = 0) {
    
    res[u] = upper_bound(pfx_b.begin(), pfx_b.end(), A) - pfx_b.begin() - 1;

    for (auto &[v, a, b]: adj[u]) {
        if (v == p) continue;
        pfx_b.push_back(B + b);
        dfs(v, u, A + a, B + b);
        pfx_b.pop_back();
    }
}
void solve() {

    cin >> n;
    adj.clear();
    pfx_b.clear();
    adj.resize(n);
    res.resize(n);
    
    for (int i = 1; i < n; i++) {
        int p, a, b;
        cin >> p >> a >> b;
        adj[i].push_back({p - 1, a, b});
        adj[p - 1].push_back({i, a, b});
    }
    pfx_b.push_back(0);
    dfs(0);
    for (int i = 1; i < n; i++) cout << res[i] << " ";
}
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
		cout << '\n';
	}
	return 0;
}