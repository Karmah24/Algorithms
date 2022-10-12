#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void testcase() {

    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, pair<int, int>> mp;
    vector<int> res;
    bool f = 1;
    for (int i = 0; i < n && f; i++) {
        for (int j = i + 1; j < n && f; j++) {

            int k = t - a[i] - a[j];
            if (mp.count(k)) {

                res = {mp[k].first, mp[k].second, i, j};
                f = 0;
            }
        }
        for (int j = 0; j < i; j++) mp[a[i] + a[j]] = {j, i};
    }
    if (f) cout << "IMPOSSIBLE";
    else for (auto &e: res) cout << e + 1 << " ";
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
