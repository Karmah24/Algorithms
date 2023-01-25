#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e3 + 5;
//================================================================

int n, m;
int grid[N][N];
int dp[N][2][2];

bool check(int i, int prv, int cur, int nxt) {

	bool ok = 1;
	for (int j = 0; j < m && ok; j++) {
		bool f = 0;
		if (i > 0 && (grid[i - 1][j] + prv) % 2 == (grid[i][j] + cur) % 2) f = 1;
		if (j > 0 && grid[i][j - 1] == grid[i][j]) f = 1; 
		if (j < m - 1 && grid[i][j + 1] == grid[i][j]) f = 1;
		if (i < n - 1 && (grid[i + 1][j] + nxt) % 2 == (grid[i][j] + cur) % 2) f = 1;
		if (!f) ok = 0;
 	}
	return ok;
}

int solve(int i, int prv, int cur) {

	if (i == n) return 0;
	int &res = dp[i][prv][cur];
	if (res != -1) return res;

	int op1 = INF, op2 = INF;
	if (check(i, prv, cur, 0)) op1 = solve(i + 1, cur, 0);
	if (check(i, prv, cur, 1)) op2 = solve(i + 1, cur, 1);
	if (op2 != INF) op2++;
	return res = min(op1, op2);
}

void testcase() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    }
	memset(dp, -1, sizeof(dp));
	int op1 = solve(0, 0, 0);
	int op2 = solve(0, 0, 1);
	if (op2 != INF) op2++;
	int res = min(op1, op2);
	cout << ((res != INF) ? res : -1);
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
