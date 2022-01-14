#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
//=======================

int treeCount(int y1, int x1, int y2, int x2, vector<vector<int>> &grid) {

    int res = grid[y2][x2];
    res -= y1 == 0 ? 0 : grid[y1 - 1][x2];
    res -= x1 == 0 ? 0 : grid[y2][x1 - 1];
    res += (x1 == 0 || y1 == 0) ? 0 : grid[y1 - 1][x1 - 1];
    return res;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            grid[i][j] = ch == '.' ? 0 : 1;
        }
    }
    for (auto &row: grid) {
        for (int i = 1; i < n; i++) {
            row[i] += row[i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            grid[j][i] += grid[j - 1][i];
        }
    }
    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << treeCount(y1 - 1, x1 - 1, y2 - 1, x2 - 1, grid) << ln;
    }
    return 0;
}