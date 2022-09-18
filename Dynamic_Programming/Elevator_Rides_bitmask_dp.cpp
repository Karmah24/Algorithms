#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int n, x;
int weight[21];
vector<pair<int, int>> dp; // <min rides, min total weight of last trip>

pair<int, int> solve(int mask) {

	auto &res = dp[mask];
	if (res.first != -1) return res;
	if (mask == 0) return res = {1, 0};

	res = {21, 0};
	for (int i = 0; i < n; i++) {

		if (!(mask & (1 << i))) continue;

		auto option = solve(mask ^ (1 << i));
		if (option.second + weight[i] <= x) {

			option.second += weight[i];
		}
		else {

			option.second = weight[i];
			option.first++;
		}
		res = min(res, option);
	}
	return res;
}

void testcase() {

    cin >> n >> x;
	dp.assign(1 << n, {-1, -1});
	for (int i = 0; i < n; i++) cin >> weight[i];
    cout << solve((1 << n) - 1).first;
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
