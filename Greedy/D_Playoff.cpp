#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

void testcase() {

	int n;
	string s;
	cin >> n >> s;
	int m = (1 << n);

	int cnt1 = count(s.begin(), s.end(), '1');
	int cnt0 = n - cnt1;

	int hi = (1 << cnt0) - 1, lo = (1 << cnt1) - 1;
	for (int i = lo + 1; i <= m - hi; i++) cout << i << " ";
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
