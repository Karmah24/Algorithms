#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<vector<int>> customer(n, vector<int>(3));
    for (int i = 0; i < n; i++) {

        cin >> customer[i][0] >> customer[i][1];
		customer[i][2] = i;
    }
	sort(customer.begin(), customer.end());
	set<pair<int, int>> rooms;
	vector<int> res(n);

	for (int i = 0; i < n; i++) {

		int idx = customer[i][2], arr = customer[i][0], dep = customer[i][1];

		if (rooms.empty() || rooms.begin()->first >= arr) res[idx] = rooms.size() + 1;
		else {

			res[idx] = rooms.begin()->second;
			rooms.erase(rooms.begin());
		}
		rooms.insert({dep, res[idx]});
	}
	cout << rooms.size() << '\n';
	for (auto &e: res) cout << e << " ";
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
