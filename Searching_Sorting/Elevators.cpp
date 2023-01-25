#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

void testcase() {

	int n, m, h;
	cin >> n >> m >> h;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	sort(b.begin(), b.end());

	auto check = [&](int t) -> bool {
		if (2 * h + b.back() - 1 > t) return 0;
		int req_elevators = 0, prv_time = t + 1;
		for (int i = n - 1; i >= 0; i--) {
			int req_time = 2 * h;
			if (prv_time + req_time <= t) prv_time += req_time;
			else {
				prv_time = req_time + b[i] - 1;
				if (++req_elevators > m) return 0;
			}
		}
		return 1;
	};
	int lo = 1, hi = INF, res;
	while (lo <= hi) {
	
		int mid = (lo + hi) / 2;
		if (check(mid)) {
			res = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
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
