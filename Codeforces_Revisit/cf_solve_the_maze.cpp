#include <bits/stdc++.h>
using namespace std;
//================================================================

bool solve() {
    int n, m;
    cin >> n >> m;
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    vector<vector<char>> grid(n + 2, vector<char>(m + 2, '_'));
    for (int i = 0; i < n + 2; i++) grid[i][0] = grid[i][m + 1] = '#';
    for (int j = 0; j < m + 2; j++) grid[0][j] = grid[n + 1][j] = '#';
    bool res = true, g = false;
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            char u;
            cin >> u;
            if (u == 'G') g = true;
            if (grid[r][c] == '_') grid[r][c] = u;
            else if (u == 'G') res = false;
            if (u == 'B') {
                grid[r][c] = u;
                for (int i = 0; i < 4; i++) {
                    char &v = grid[r + dy[i]][c + dx[i]];
                    if (v == 'G') res = false;
                    v = '#';
                }
            }
        }
    }
    if ((grid[n][m] == '#' && g) || !res) return false;
    queue<pair<int, int>> q;
    q.push({n, m});
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            char &v = grid[r + dy[i]][c + dx[i]];
            if (v == '.' || v == 'G') {
                q.push({r + dy[i], c + dx[i]});
                grid[r + dy[i]][c + dx[i]] = '#';
            }
        }
    }
    for (int r = 1; r < n + 1; r++) {
        for (int c = 1; c < m + 1; c++) if (grid[r][c] == 'G') return false;
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}