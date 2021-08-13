#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;

void monsterReach(vector<vector<char>> &grid, queue<pair<int, int>> &q) {

    while (!q.empty()) {
        auto [y1, x1] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {

            int x2 = x1 + dx[i], y2 = y1 + dy[i];
            if (y2 < 0 || y2 == n || x2 < 0 || x2 == m || grid[y2][x2] == '#') continue;

            if (grid[y2][x2] == '.') {
                grid[y2][x2] = grid[y1][x1] + 1;
                q.push({y2, x2});
            }
        }
    }
}

string safePath(vector<vector<char>> &grid, pair<int, int> st) {

    queue<pair<pair<int ,int>, int>> q;
    pair<int, int> par[n][m];
    pair<int, int> fin = {-1, -1};
    q.push({st, 0});

    while (!q.empty()) {

        auto [y1, x1] = q.front().first;
        int lvl = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int y2 = y1 + dy[i], x2 = x1 + dx[i];
            if (grid[y2][x2] == '#' || (grid[y2][x2] != '.' && grid[y2][x2] <= lvl + '0')) continue;

            par[y2][x2] = {y1, x1};
            if (y2 == 0 || y2 == n - 1 || x2 == 0 || x2 == m - 1) {
                fin = {y2, x2};
                break;
            }
            q.push({{y2, x2}, lvl + 1});
        }
        if (fin.first != -1) break;
    }
    if (fin.first == -1) return "NO";
    string path = "";
    auto [y, x] = fin;
    while (!(y == st.first && x == st.second)) {

        auto [yp, xp] = par[y][x];

        if (y == yp + 1) path.push_back('D');
        else if (y == yp - 1) path.push_back('U');
        else if (x == xp + 1) path.push_back('R');
        else path.push_back('L');

        y = yp, x = xp;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    pair<int, int> st;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') st = {i, j};
            else if (grid[i][j] == 'M') {
                q.push({i, j});
                grid[i][j] = '0';
            }
        }
    }
    grid[st.first][st.second] = '.';
    monsterReach(grid, q);
    string res = safePath(grid, st);
    if (res == "N0") cout << "NO";
    else {
        cout << "YES\n";
        cout << res.size() << '\n' << res;
    }
    return 0;
}