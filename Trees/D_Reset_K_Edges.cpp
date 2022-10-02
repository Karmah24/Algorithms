#include <bits/stdc++.h>
using namespace std;
//================================================================

int n, k;
vector<vector<int>> adj;
vector<int> par, height;
int cuts;

void dfs1(int u, int h) {


    for (auto &v: adj[u]) {

        if (v == par[u]) continue;
        par[v] = u;
        dfs1(v, h);
        height[u] = max(height[u], height[v] + 1);
    }
    if (height[u] == h - 1 && par[u] != 0 && u != 0) {

        cuts++;
        height[u] = -1;
    }
}

bool check(int h) {

    cuts = 0;
    height.assign(n, 0);
    dfs1(0, h);
    return cuts <= k;
}

void testcase() {

    cin >> n >> k;
    
    adj.assign(n, vector<int>());
    par.assign(n, -1);
    for (int u = 1; u < n; u++) {
    
        int p;
        cin >> p;
        p--;
        adj[u].push_back(p);
        adj[p].push_back(u);
    }
    int lo = 1, hi = n, res;
    while (lo <= hi) {

        int mid = (lo + hi) / 2;
        if (check(mid)) {

            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << res;
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
