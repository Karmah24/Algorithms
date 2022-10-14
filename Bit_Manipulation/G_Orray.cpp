#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

void testcase() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<bool> vis(n, 0);
	int curr = 0;
	while (true) {
		int idx = max_element(a.begin(), a.end(), [&](int x, int y) {
			return (curr | x) < (curr | y);
		}) - a.begin();

		if ((curr | a[idx]) == curr) break;
		cout << a[idx] << " ";
		vis[idx] = 1;
		curr |= a[idx];
	}

	for (int i = 0; i < n; i++) if (!vis[i]) cout << a[i] << " ";
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
