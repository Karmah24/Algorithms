#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

void testcase() {

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> a[i];

    vector<vector<int>> vals(m + 1);
    for (int i = 1; i < n + 1; i++) {

        if (a[i] > n) continue;
        int l = a[i] >= 0 ? 1 : ceil(double(-a[i]) / i);
        int r = min(m, (n - a[i]) / i);

        for (int j = l; j < r + 1; j++) vals[j].push_back(a[i] + i * j);
    }
    for (int i = 1; i < m + 1; i++) {

        int sz = vals[i].size();
        vector<int> exists(sz + 1, 0);
        for (auto &e: vals[i]) if (e < sz) exists[e] = 1;
        int mex = 0;
        while (exists[mex]) mex++;
        cout << mex << '\n';
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
