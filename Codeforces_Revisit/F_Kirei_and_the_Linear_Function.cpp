// problem reduced to finding 2 numbers a and c such that
// (a * b + c) % 9 == k, for a given b and k
// with modulo ops only looking at a % 9, b % 9 and c % 9 was sufficient
// (((a % 9) * (b % 9)) % 9 + (c % 9)) % 9 == k
// thus there were only 9 possible values for a and c
// giving 81 total combinations
// iterate over these possible combos to get the answer

#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

	string s;
	int w, q;
	cin >> s >> w >> q;
	int n = s.size();

	vector<int> pfx(n + 1);
	pfx[0] = 0;
	for (int i = 1; i <= n; i++) {

		pfx[i] = pfx[i - 1] + s[i - 1] - '0';
 	}
	vector<deque<int>> mp(9, deque<int>());
	for (int i = 1; i <= n - w + 1; i++) {

		int s = pfx[i + w - 1] - pfx[i - 1];
		mp[s % 9].push_back(i);
	}
	while (q--) {

		int l, r, k;
		cin >> l >> r >> k;
		int l1, l2;
		pair<int, int> res = {n + 1, n + 1};
		for (int a = 0; a < 9; a++) {

			if (mp[a].empty()) continue;
			l1 = mp[a].front();
			mp[a].pop_front();

			for (int c = 0; c < 9; c++) {

				if (mp[c].empty()) continue;
				l2 = mp[c].front();

				int b = (pfx[r] - pfx[l - 1]) % 9;
				if ((((a * b) % 9) + c) % 9 != k) continue;

				res = min(res, {l1, l2});
			}
			mp[a].push_front(l1);
		}
        if (res.first == n + 1) cout << "-1 -1\n";
		else cout << res.first << " " << res.second << '\n';
	}
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
		// cout << '\n';
	}
	return 0;
}
