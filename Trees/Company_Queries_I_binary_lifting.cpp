#include <bits/stdc++.h>
using namespace std;
//================================================================

vector<vector<int>> adj, up;

void binary_lifting(int u, int par) {

    up[u][0] = par;
    for (int i = 1; i < 20; i++) {

        int v = up[u][i - 1];
        if (v != -1) up[u][i] = up[v][i - 1];
    }
    for (auto &v: adj[u]) {

        if (v != par) binary_lifting(v, u);
    }
}

int lift(int u, int k) {

    int ances = u;
    for (int i = 0; i < 20 && ances != -1; i++) {

        if (k & (1 << i)) ances = up[ances][i];
    }
    return ances;
}

void testcase() {

    int n, q;
    cin >> n >> q;
    
    adj.assign(n, vector<int>());
    up.assign(n, vector<int>(20, -1));
    for (int i = 1; i < n; i++) {

        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    binary_lifting(0, -1);
    while (q--) {

        int x, k;
        cin >> x >> k;
        x--;
        int res = lift(x, k);
        if (res != -1) res++;
        cout << res << '\n';
    }
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
