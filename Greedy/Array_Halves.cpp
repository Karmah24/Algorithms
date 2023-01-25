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
	vector<int> a(2 * n);
	for (int i = 0; i < 2 * n; i++) cin >> a[i];

	int res = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > n) {
			cnt++;
			res += n - i;
		}
	}
	for (int i = n; i < 2 * n; i++) {
		if (a[i] <= n) {
			res += i - n + 1;
		}
	}
	cout << res - cnt;
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
