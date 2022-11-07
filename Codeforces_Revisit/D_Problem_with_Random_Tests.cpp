#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

int n;
string s;

string solve(int st) {

    string res = s;
    int i = 0, j = st;
    for (; j < n; j++, i++) {
        res[j] = ((s[i] - '0') | (s[j] - '0')) + '0';
    }
    return res;
}

void testcase() {

    cin >> n >> s;
    
    int i = 0;
    while (i < n && s[i] == '0') i++;
    if (i == n) s = "0";
    else s = s.substr(i, n - i);

    string best = s;

    for (int i = 0; i <= 30; i++) {

        string op = solve(i);
        if (op > best) best = op;
    }
    cout << best;
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
