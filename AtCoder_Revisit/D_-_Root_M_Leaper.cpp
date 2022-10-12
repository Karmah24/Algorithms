#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

void testcase() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> d;
    for (int i = 0; i * i <= m; i++) {

        int x = m - (i * i);
        double j = sqrt(x);
        if (j != floor(j)) continue;
        d.push_back({i, j});
        d.push_back({-i, j});
        d.push_back({i, -j});
        d.push_back({-i, -j});
    }
    vector<vector<int>> res(n + 1, vector<int>(n + 1, -1));
    res[1][1] = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});
    while (!q.empty()) {

        auto [x, y] = q.front(); q.pop();
        for (auto &[dx, dy]: d) {

            int nx = x + dx, ny = y + dy;
            if (nx <= 0 || ny <= 0 || nx > n || ny > n || res[nx][ny] != -1) continue;
            res[nx][ny] = res[x][y] + 1;
            q.push({nx, ny});
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) cout << res[i][j] << " ";
        cout << '\n';
    }
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
