#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

void testcase() {

    int n, q;
    string s;
    cin >> n >> q >> s;
    s = "$" + s;
    vector<string> p = {"abc", "acb", "bac", "bca", "cab", "cba"};
    vector<string> t(6, "$");
    for (int i = 0; i < 6; i++) {

        for (int j = 0; j <= n / 3; j++) t[i] += p[i];
        int x = (3 - (n % 3)) % 3;
        while (x--) t[i].pop_back();
    }
    vector<vector<int>> pfx(6, vector<int>(n + 1, 0));
    for (int i = 0; i < 6; i++) {
        for (int j = 1; j < n + 1; j++) {
            pfx[i][j] = pfx[i][j - 1] + (t[i][j] != s[j]);
        }
    }
    while (q--) {

        int l, r;
        cin >> l >> r;
        int res = n;
        for (int i = 0; i < 6; i++) {
            res = min(res, pfx[i][r] - pfx[i][l - 1]);
        }
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
