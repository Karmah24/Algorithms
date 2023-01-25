#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 305;
//================================================================

double n;
vector<vector<vector<double>>> dp;

double solve(int cnt1, int cnt2, int cnt3) {

    if (cnt1 < 0 || cnt2 < 0 || cnt3 < 0) return 0;
    int cnt0 = n - (cnt1 + cnt2 + cnt3);
    if (cnt0 == n) return 0;
    double &res = dp[cnt1][cnt2][cnt3];
    if (res != -1) return res;

    double op1 = (solve(cnt1 - 1, cnt2, cnt3) + 1) * (cnt1 / n);
    double op2 = (solve(cnt1 + 1, cnt2 - 1, cnt3) + 1) * (cnt2 / n);
    double op3 = (solve(cnt1, cnt2 + 1, cnt3 - 1) + 1) * (cnt3 / n);

    return res = ((op1 + op2 + op3 + cnt0 / n) * n) / (n - cnt0);

    // Ea = (1+Eb) * C1/N + (1+Ec) * C2/N + (1+Ed) * C3/N + (1+Ea) * C0/N
    // Ea(1 - C0/N) = (1+Eb) * C1/N + (1+Ec) * C2/N + (1+Ed) * C3/N + C0/N
}

void testcase() {

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> cnt(4, 0);
    for (int i = 0; i < n; i++) cnt[a[i]]++;
    dp.assign(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, -1)));
    double res = solve(cnt[1], cnt[2], cnt[3]);
    cout << fixed << setprecision(9) << res;
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
