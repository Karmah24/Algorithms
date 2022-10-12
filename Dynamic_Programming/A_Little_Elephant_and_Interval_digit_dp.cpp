#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int dp[20][2][2];

int first = -1;
int solve(string &n, int i, int fr = 0, int fz = 1) {

    int r = fr ? 9 : n[i] - '0';
    if (i == n.size() - 1) {
        if (fz) return r + 1;
        return r >= first;
    }
    int &res = dp[i][fr][fz];
    if (res != -1) return res;

    res = 0;
    for (int d = 0; d <= r; d++) {

        if (fz && d > 0) first = d; 
        res += solve(n, i + 1, fr || d < r, fz && d == 0);
    }
    return res;
}


void testcase() {

    int l, r;
    cin >> l >> r;
    string a = to_string(l - 1), b = to_string(r);
    memset(dp, -1, sizeof(dp));
    int x = solve(b, 0);
    memset(dp, -1, sizeof(dp));
    int y = solve(a, 0);
    cout << x - y;
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
