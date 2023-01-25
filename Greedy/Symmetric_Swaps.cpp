#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

void testcase() {

    int n;
    cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

	vector<pair<int, int>> c;
	for (int i = 0; i < n; i++) {
		c.push_back({a[i], i});
		c.push_back({b[i], i});
	}
	sort(c.begin(), c.end());
	vector<int> cnt(n, 0);
	int l = 0, r = 0, uniq = 0, res = INF;
	while (r < 2 * n) {

		if (++cnt[c[r].second] == 1) uniq++;
		while (uniq == n) {
			res = min(res, c[r].first - c[l].first);
			if (--cnt[c[l].second] == 0) uniq--;
			l++;
		}
		r++;
	}
	cout << res;
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
