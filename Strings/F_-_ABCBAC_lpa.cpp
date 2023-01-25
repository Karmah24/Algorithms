#include <bits/stdc++.h>
using namespace std;
//================================================================

int lps(string &s) {
    int n = s.size();
    vector<int> lps(n);
    lps[0] = 0;
    for (int i = 1; i < n; i++) {
        int l = lps[i - 1];
        while (l > 0 && s[l] != s[i]) l = lps[l - 1];
        if (s[l] == s[i]) l++;
        lps[i] = l;
    }
    return lps[n - 1];
}

void testcase() {

    int n;
    string t;
    cin >> n >> t;

    string s1 = t.substr(0, n);
    string s2 = t.substr(n, n);
    reverse(s2.begin(), s2.end());
    string s = s1 + s2;
    int i = min(n, lps(s));

    string rev = t.substr(i, n);
    string res = rev;
    reverse(res.begin(), res.end());

    string req = res.substr(0, i) + rev + res.substr(i, n - i);
    cout << (req == t ? res : "-1");
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
