#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int R, C;
vector<vector<char>> grid;
vector<vector<int>> dp;

bool dfs(int r, int c, int n = 1) {

    if (r >= R || r < 0 || c >= C || c < 0 || grid[r][c] == '#') return 0;
    int &res = dp[r][c];
    if (res != -1) return res;
    if (grid[r][c] == 'S') {
        return n >= 4;
    }
    grid[r][c] = '#';
    for (int i = 0; i < 4; i++) {
        int nr = r + dy[i], nc = c + dx[i];
        if (dfs(nr, nc, n + 1)) return res = 1;
    }
    grid[r][c] = '.';
    return res = 0;
}

void testcase() {

    cin >> R >> C;
    grid.assign(R, vector<char>(C));
    dp.assign(R, vector<int>(C, -1));
    int sr, sc;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                sr = i, sc = j;
            }
        }
    }
    bool ok = 0;
    for (int i = 0; i < 4; i++) {
        ok |= dfs(sr + dy[i], sc + dx[i]);
    }
    cout << (ok ? "Yes" : "No");
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
