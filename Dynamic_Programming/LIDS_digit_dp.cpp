#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

string a, b;
int dp[12][12][12][2][2][2];

int cal(int pos, int prev, int cnt, bool fl, bool fr, bool f_zero) {

    if (pos == b.size()) return cnt == 0;

    int &res = dp[pos][prev + 1][cnt][fl][fr][f_zero];
    if (res != -1) return res;

    res = 0;
    int l = fl ? 0 : a[pos] - '0';
	int r = fr ? 9 : b[pos] - '0';

    for (int dgt = l; dgt <= r; dgt++) {

		res += cal(pos + 1, prev, cnt, fl || dgt > l, fr || dgt < r, f_zero || dgt);
		if (dgt > prev && cnt && (f_zero || dgt)) {
			res += cal(pos + 1, dgt, cnt - 1, fl || dgt > l, fr || dgt < r, f_zero || dgt);
		}
    }
    return res;
}

void testcase() {

    cin >> a >> b;
	a.insert(a.begin(), b.size() - a.size(), '0');
    memset(dp, -1, sizeof(dp));
	int len, res;
	for (len = 10; len >= 1; len--) {
		res = cal(0, -1, len, false, false, false);
		if (res > 0) break;
	}
	cout << len << " " << res;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
		testcase();
		cout << '\n';
	}
	return 0;
}