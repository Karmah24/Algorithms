#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void testcase() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> sets(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> sets[i][j];
    }
    map<vector<int>, pair<int, int>> mp;
    for (int i = 0; i < n; i++) mp[sets[i]] = {i, 0};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            vector<int> v(m);
            for (int k = 0; k < m; k++) {

                if (sets[i][k] == sets[j][k]) v[k] = sets[i][k];
                else v[k] = 3 - sets[i][k] - sets[j][k];
            }
            if (mp.count(v) && mp[v].first > j) {

                mp[sets[i]].second++, mp[sets[j]].second++, mp[v].second++;
            }
        }
    }

    int res = 0;
    for (auto &[k, v]: mp) {
        
        res += (v.second * (v.second - 1)) / 2;
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
