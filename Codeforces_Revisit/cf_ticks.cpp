#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================

bool solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> grid(n + 1, vector<pair<int, int>>(m + 2, {-1, -1}));
    vector<vector<int>> centers;
    vector<vector<bool>> visl(n + 1, vector<bool>(m + 1, false));
    vector<vector<bool>> visr(n + 1, vector<bool>(m + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            if (ch == '.') continue;
            grid[i][j].first = grid[i - 1][j - 1].first + 1;
            grid[i][j].second = grid[i - 1][j + 1].second + 1;
            int d = min(grid[i][j].first, grid[i][j].second);
            if (d >= k) centers.push_back({i - d, i, j});
        }
    }
    sort(centers.begin(), centers.end());
    for (auto &center: centers) {
        int d = center[1] - center[0], i = center[1], j = center[2];
        for (int k = 1; k <= d; k++) {
            if (visl[i - k][j - k]) break;
            visl[i - k][j - k] = 1;
        }
        for (int k = 1; k <= d; k++) {
            if (visr[i - k][j + k]) break;
            visr[i - k][j + k] = 1;
        }
        visl[i][j] = visr[i][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j].first != -1 && !(visl[i][j] || visr[i][j])) return false;
        }
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}