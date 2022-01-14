#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;

void solve(vector<vector<char>> &grid, pair<int, int> st, pair<int, int> fin) {
    
    queue<pair<int, int>> q;
    pair<int, int> par[n][m];
    q.push(st);

    bool pathExists = false;
    while (!q.empty()) {
        auto [y1, x1] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {

            int x2 = x1 + dx[i], y2 = y1 + dy[i];
            if (y2 < 0 || y2 == n || x2 < 0 || x2 == m || grid[y2][x2] == '#') continue;
            par[y2][x2] = {y1, x1};
            if (y2 == fin.first && x2 == fin.second) {
                pathExists = true;
                break;
            }
            grid[y2][x2] = '#';
            q.push({y2, x2});
        }
        if (pathExists) break;
    }
    if (!pathExists) {
        cout << "NO";
        return;
    }
    string path = "";
    int y = fin.first, x = fin.second;
    while (!(y == st.first && x == st.second)) {

        auto [yp, xp] = par[y][x];
        if (y == yp + 1) path.push_back('D');
        else if (y == yp - 1) path.push_back('U');
        else if (x == xp + 1) path.push_back('R');
        else path.push_back('L');
        y = yp, x = xp;
    }
    reverse(path.begin(), path.end());
    cout << "YES\n" << path.size() << '\n' << path;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    pair<int, int> st, fin;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') st = {i, j};
            else if (grid[i][j] == 'B') fin = {i, j};
        }
    }
    grid[st.first][st.second] = '#';
    solve(grid, st, fin);
    return 0;
}