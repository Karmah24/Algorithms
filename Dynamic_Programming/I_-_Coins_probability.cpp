#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 3e3 + 5;
//================================================================

vector<vector<double>> dp;
int n;
vector<double> p;

double solve(int i, int h) {

    if (i == 0) return h == 0;
    double &res = dp[i][h];
    if (res != -1) return res;

    return res = solve(i - 1, h) * (1 - p[i]) + solve(i - 1, h - 1) * p[i];
}

void testcase() {

    cin >> n;
    p.resize(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> p[i];

    double res = 0;
    dp.assign(n + 1, vector<double>(n + 1, -1));
    for (int h = n / 2 + 1; h < n + 1; h++) res += solve(n, h);
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
