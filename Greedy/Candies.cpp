#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

void testcase() {

	int n, m;
	cin >> n >> m;
	vector<int> a(m + 1), c(m + 1);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i < m + 1; i++) cin >> c[i];

	vector<int> pfx(m + 1, 0);
	for (int i = 1; i < m + 1; i++) pfx[i] = pfx[i - 1] + a[i];

	int res = 0;
	for (int p = 1; p < m + 1; p++) {
		int curr = 0;
		for (int k = 1; k * p < m + 1; k++) {
			int cnt = pfx[min((k + 1) * p - 1, m)] - pfx[k * p - 1];
			curr += cnt * k;
		}
		res = max(res, curr * c[p]);
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
