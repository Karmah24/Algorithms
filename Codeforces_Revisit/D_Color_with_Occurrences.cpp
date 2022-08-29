#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {

	string t;
	int n;
	cin >> t >> n;
	vector<string> s(n);
	for (auto &e: s) cin >> e;

	vector<pair<int, int>> a(t.size());
	for (int i = 0; i < t.size(); i++) {

		int idx = -1, sz = 0;
		for (int j = 0; j < n; j++) {
			int k;
			for (k = 0; k < s[j].size(); k++) {
				if (t[i + k] != s[j][k]) break;
			}
			if (sz < k && s[j].size() == k) {
				sz = k;
				idx = j;
			}
		}
		a[i] = {sz, idx};
	}
	int reach = a[0].first, steps = a[0].first;
	if (reach == 0) {
		cout << "-1\n";
		return;
	}
	pair<int, int> jump;
	vector<pair<int, int>> jumps;
	jumps.push_back({0, a[0].second});
	for (int i = 1; i < t.size(); i++) {

		if (reach < i + a[i].first) {
			reach = i + a[i].first;
			jump = {i, a[i].second};
		}
		if (--steps == 0) {
			jumps.push_back(jump);
			steps = reach - i;
			if (steps == 0) break;
		}
	}
	if (reach < t.size()) cout << "-1\n";
	else {
		cout << jumps.size() << '\n';
		for (auto &[f, s]: jumps) cout << s + 1 << " " << f + 1 << '\n';
	}
}
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}