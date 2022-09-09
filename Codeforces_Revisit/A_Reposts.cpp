#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

	int q;
    cin >> q;
    map<string, int> mp;
    mp["polycarp"] = 1;
    int res = 1;
    while (q--) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        transform(s3.begin(), s3.end(), s3.begin(), ::tolower);
        mp[s1] = mp[s3] + 1;
        res = max(res, mp[s1]);
    }
    cout << res;
}

signed main() {
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
