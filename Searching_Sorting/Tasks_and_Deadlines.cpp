// Given n tasks (duration(a) and deadline(d)) find max profit.
// Profit for each task = deadline - finish time.
// Total profit = d1 - a1 + d2 - (a1 + a2) + d3 - (a1 + a2 + a3) ...
// = ∑ (di - (a1 + a2 + a3 ... ai))
// We need to minimize second part; smallest ai should repeat maximum times
// Therefore, we process the tasks in inc order of ai;

#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (auto &[f, s]: tasks) cin >> f >> s;
    sort(tasks.begin(), tasks.end());

    for (int i = 1; i < n; i++) tasks[i].first += tasks[i - 1].first;
    int res = 0;
    for (int i = 0; i < n; i++) {

        res += tasks[i].second - tasks[i].first;
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
