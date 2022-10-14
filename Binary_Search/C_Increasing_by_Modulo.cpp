#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

void testcase() {

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	auto check = [&](int x) -> bool {

		int prev = 0;
		for (int i = 0; i < n; i++) {
			int d = 0;
			if (a[i] <= prev) {
				d = prev - a[i];
				if (d > x) return 0;
			}
			else {
				d = m - (a[i] % m) + prev;
				if (d > x) prev = a[i];
			}
		}
		return 1;
	};
	int lo = 0, hi = m, res = -1;
	while (lo <= hi) {
	
		int mid = (lo + hi) / 2;
		if (check(mid)) {
	
			res = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << res;
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
