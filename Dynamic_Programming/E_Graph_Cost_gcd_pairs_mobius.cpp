#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e6 + 5;
//================================================================

void testcase() {

	int n, m;
	cin >> n >> m;

	vector<int> dp(n + 1, 0); // dp[k] = number of pairs (i, j) : gcd(i, j) = k
	for (int i = n; i >= 1; i--) {
		int x = n / i;
		dp[i] = (x * (x - 1)) / 2;
		for (int j = 2 * i; j < n + 1; j += i) dp[i] -= dp[j]; 
	}

	int res = 0;
	for (int i = n - 1; i >= 1 && m; i--) {
		if (dp[i + 1] < i) continue;
		int cnt = min(dp[i + 1] / i, m / i);
		m -= cnt * i;
		res += cnt * (i + 1);
	}
	if (m) cout << -1;
	else cout << res;
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
