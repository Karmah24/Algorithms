#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 5;

#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) { return ((x % MOD) + (y % MOD)) % MOD; }
//================================================================

int n, m;
int dp[1005][(1 << 10) + 5];

void generate_next_masks(int i, int curr_mask, int next_mask, vector<int> &next_masks) {

	if (i == n) {
		next_masks.push_back(next_mask);
		return;
	}

	if (curr_mask & (1 << i)) {
		generate_next_masks(i + 1, curr_mask, next_mask, next_masks);
	}
	else {

		if ((i < n - 1) && !(curr_mask & (1 << (i + 1)))) {
			generate_next_masks(i + 2, curr_mask, next_mask, next_masks);
		}
		generate_next_masks(i + 1, curr_mask, next_mask | (1 << i), next_masks);
	}

}

int solve(int i, int mask) {

	if (i == m) return mask == 0;
	int &res = dp[i][mask];
	if (res != -1) return res;

	res = 0;
	vector<int> next_masks;
	generate_next_masks(0, mask, 0, next_masks);
	for (auto &nxt: next_masks) {

		res = add(res, solve(i + 1, nxt));
	}
	return res;
}

void testcase() {

	cin >> n >> m;

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0);
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
