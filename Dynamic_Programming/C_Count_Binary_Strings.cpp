#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 100 + 5;
const int MOD = 998244353;
//================================================================

int dp[N][N];
int m[N][N];
int n;

int solve(int i, int last) {

    if (i > n) return 1;
    int &res = dp[i][last];
    if (res != -1) return res;

    bool same = 0;
    for (int r = 1; r <= i; r++) {
        if (m[r][i] == 1) {
            if (r != i) same = 1;
            if (last > r) return res = 0;
        }
        else if (m[r][i] == 2) {
            if (r == i) return res = 0;
            if (last <= r) last = i;
        } 
    }
    res = solve(i + 1, last);
    if (last != i && !same) res += solve(i + 1, i);
    res %= MOD;
    return res;
}

void testcase() {

    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        for (int j = i; j < n + 1; j++) cin >> m[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}