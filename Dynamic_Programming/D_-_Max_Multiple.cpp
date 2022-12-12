#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e12;
const int N = 1e2 + 5;
//================================================================

int n, k, d;
vector<int> a;
int dp[N][N][N];

int solve(int i, int s, int k) {

    if (i < 0) {
        if (k == 0 && s == 0) return 0;
        else return -INF;
    }
    int &res = dp[i][s][k];
    if (res != -1) return res;
    int ifout = solve(i - 1, s, k);
    int ifin = (k > 0) ? solve(i - 1, (s + a[i]) % d, k - 1) : -INF;
    if (ifin != -INF) ifin += a[i];
    return res = max(ifin, ifout);
}

void testcase() {

    cin >> n >> k >> d;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    int res = solve(n - 1, 0, k);
    cout << ((res == -INF) ? -1 : res);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
