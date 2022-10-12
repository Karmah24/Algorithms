#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<pair<int, int>> pos(3);
    for (int i = 0; i < 3; i++) cin >> pos[i].first >> pos[i].second;
    int r, c;
    cin >> r >> c;

    map<int, int> mpr, mpc;
    for (auto &e: pos) {

        mpr[e.first]++;
        mpc[e.second]++;
    }
    pair<int, int> pivot;
    for (int i = 0; i < 3; i++) {

        if (mpr[pos[i].first] == 2 && mpc[pos[i].second] == 2) pivot = pos[i];
    }
    bool ok = 0;
    if (r == pivot.first || c == pivot.second) ok = 1;
    set<pair<int, int>> corners({{1, 1}, {1, n}, {n, 1}, {n, n}});
    if (!corners.count(pivot)) {
        ok = (abs(pivot.first - r) % 2 == 0) || (abs(pivot.second - c) % 2 == 0);
    }
    if (ok) cout << "YES";
    else cout << "NO";
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
