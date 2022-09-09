#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 5;
//================================================================

void testcase() {

	int n;
    cin >> n;

    int c;
    string s;
    vector<string> pos = {"A", "B", "C", "AB", "AC", "BC", "ABC"};
    map<string, int> mp;
    for (auto &e: pos) mp[e] = INF;

    for (int i = 0; i < n; i++) {

        cin >> c >> s;
        sort(s.begin(), s.end());
        mp[s] = min(mp[s], c);
    }
    int res = min({
        mp["ABC"],
        mp["BC"] + mp["A"],
        mp["AC"] + mp["B"],
        mp["AB"] + mp["C"],
        mp["AB"] + mp["AC"],
        mp["AB"] + mp["BC"],
        mp["BC"] + mp["AC"],
        mp["A"] + mp["B"] + mp["C"]});

    if (res < INF) cout << res;
    else cout << -1;
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
