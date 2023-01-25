#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
const int INF = 1e18;
//================================================================

void testcase() {

	int n, q;
    cin >> n >> q;
    vector<vector<int>> pfx(N, vector<int>(N, 0));

    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        pfx[h][w] += h * w;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            pfx[i][j] += pfx[i - 1][j] + pfx[i][j - 1];
            pfx[i][j] -= pfx[i - 1][j - 1];
        }
    }
    while (q--) {
        int h1, w1, h2, w2;
        cin >> h1 >> w1 >> h2 >> w2;

        int res = pfx[h2 - 1][w2 - 1];
        res -= pfx[h2 - 1][w1] + pfx[h1][w2 - 1];
        res += pfx[h1][w1];
        cout << res << '\n';
    }
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif
	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		// cout << '\n';
	}
	return 0;
}
