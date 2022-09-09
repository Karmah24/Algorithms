#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

	int n, m;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; i++) cin >> r[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    partial_sum(r.begin(), r.end(), r.begin());
    partial_sum(b.begin(), b.end(), b.begin());

    int res = max(0, *max_element(r.begin(), r.end())) + max(0, *max_element(b.begin(), b.end()));
    cout << res;
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
		testcase();
		cout << '\n';
	}
	return 0;
}
