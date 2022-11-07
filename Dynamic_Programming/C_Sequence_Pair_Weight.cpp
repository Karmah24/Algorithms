// weight of array = # ordered pairs (i, j) : a[i] = a[j]
// cal sum of weights of all subarrays.

// subarray = (l, r); to get all subarrays iterate over all l and r (n^2).
// try fixing one end.
// cal res for all subarrays ending at a particular r = dp[r].
// dp[i] obviously contains dp[i - 1].
// by including a[i] = v, new pairs can form with all previous v.
// for each prev v at idx we can start the subarray from [0, idx].
// therefore idx + 1 vals, for all v; which can be stored in a pfx_sum map.

#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void testcase() {

	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> freq, pfx;
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) {
		if (i > 0) dp[i] = dp[i - 1] + pfx[a[i]];
		pfx[a[i]] += i + 1;
	}
	cout << accumulate(dp.begin(), dp.end(), 0LL);
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
