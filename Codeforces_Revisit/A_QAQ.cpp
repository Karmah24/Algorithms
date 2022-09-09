#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

	string s;
    cin >> s;
    int n = s.size();
    s = "$" + s;
    vector<int> pfx(n + 2, 0), sfx(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        pfx[i] = pfx[i - 1];
        if (s[i] == 'Q') pfx[i]++;
    }
    for (int i = n; i > 0; i--) {
        sfx[i] = sfx[i + 1];
        if (s[i] == 'Q') sfx[i]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') res += pfx[i] * sfx[i];
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
