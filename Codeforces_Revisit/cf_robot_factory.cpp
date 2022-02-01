#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================
int n, m;
vector<vector<int>> grid;
vector<vector<bool>> vis;
int wall[] = {8, 4, 2, 1};
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};

int dfs(int r, int c) {
    if (vis[r][c]) return 0;
    vis[r][c] = true;
    int room_size = 1;
    for (int i = 0; i < 4; i++) {
        if (grid[r][c] & wall[i]) continue;
        int r1 = r + dy[i], c1 = c + dx[i];
        room_size += dfs(r + dy[i], c + dx[i]);
    }
    return room_size;
}
void solve() {
    
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    vis.assign(n, vector<bool>(m, false));
    for (auto &row: grid) {
        for (auto &cell: row) cin >> cell;
    }
    unordered_map<int, int> rooms;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (!vis[r][c]) rooms[dfs(r, c)]++;
        }
    }
    for (int i = n * m - 1; i > 0; i--) {
        while (rooms[i]--) cout << i << " ";
    }
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}