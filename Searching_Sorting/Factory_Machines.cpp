// Always think binary search for optimization problems (minimize / maximize).

#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int n, t;
vector<int> a;

int check(int x) {

	int k = 0;
	for (auto &e: a) {

		k += min(x / e, (int)1e9);
	}
	return k;
}

void testcase() {

    cin >> n >> t;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int lo = 1, hi = 1e18, res;
	while (lo <= hi) {

		int mid = (lo + hi) / 2;
		int k = check(mid);
		if (k >= t) {

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
