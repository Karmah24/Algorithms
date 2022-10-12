#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e12;
//================================================================

const int N = 105;
int n, W;
vector<int> val(N), weight(N);
int dp[N][100005];

int solve(int n, int V) {

    if (n < 0) {
        if (V == 0) return 0;
        return INF;
    }
    int &res = dp[n][V];
    if (res != -1) return res;

    int ifin, ifout = solve(n - 1, V);
    if (val[n] > V || solve(n - 1, V - val[n]) == INF) ifin = INF;
    else ifin = solve(n - 1, V - val[n]) + weight[n];
    return res = min(ifin, ifout);
}

void testcase() {

    cin >> n >> W;
    for (int i = 0; i < n; i++) cin >> weight[i] >> val[i];
    memset(dp, -1, sizeof(dp));
    int V = 100001;
    for (; V >= 0; V--) {

        solve(n - 1, V);
        if (dp[n - 1][V] <= W) break;
    }
    cout << V;
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
