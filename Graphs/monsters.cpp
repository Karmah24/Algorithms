#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, m;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    queue<pair<int, int>> monsters;
    pair<int, int> st;
    vector<vector<int>> grid;
public:
    Solution() {

        cin >> n >> m;
        grid.assign(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                if (ch == '#') grid[i][j] = 0;
                else if (ch == 'M') {
                    monsters.push({i, j});
                    grid[i][j] = 0;
                }
                else if (ch == 'A') {
                    st = {i, j};
                }
            }
        }
    }
    void monsterReach() {

        while (!monsters.empty()) {
            auto [y1, x1] = monsters.front();
            monsters.pop();

            for (int i = 0; i < 4; i++) {

                int x2 = x1 + dx[i], y2 = y1 + dy[i];

                if (y2 < 0 || y2 == n || x2 < 0 || x2 == m) continue;
                if (grid[y2][x2] == INT_MAX) {
                    grid[y2][x2] = grid[y1][x1] + 1;
                    monsters.push({y2, x2});
                }
            }
        }
    }
    string safePath() {

        if (st.first == n - 1 || st.second == m - 1) return "";
        queue<pair<pair<int ,int>, int>> q;
        pair<int, int> par[n][m];
        pair<int, int> fin = {-1, -1};
        q.push({st, 0});

        while (!q.empty()) {

            auto [y1, x1] = q.front().first;
            int lvl = q.front().second;
            q.pop();
            grid[y1][x1] = 0;

            for (int i = 0; i < 4; i++) {

                int y2 = y1 + dy[i], x2 = x1 + dx[i];

                if ((grid[y2][x2] <= lvl + 1)) continue;

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
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    Solution obj;
    obj.monsterReach();
    string res = obj.safePath();
    if (res == "NO") cout << res;
    else {
        cout << "YES\n";
        cout << res.size() << '\n' << res;
    }
    return 0;
}