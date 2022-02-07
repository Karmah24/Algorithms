#include <bits/stdc++.h>
using namespace std;
//=======================
vector<vector<int>> grid;

int to0(int r1, int c1, int r2, int c2) {
    return grid[r2][c2] - grid[r1 - 1][c2] - grid[r2][c1 - 1] + grid[r1 - 1][c1 - 1];
}
int to1(int r1, int c1, int r2, int c2) {
    return (r2 - r1 + 1) * (c2 - c1 + 1) - to0(r1, c1, r2, c2);
}
int solve() {
    int n, m;
    cin >> n >> m;
    grid.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1] + (x == '1');
        }
    }
    int res = 16, curr_min, prev_min;

    for (int c1 = 1; c1 <= m; c1++) {
        for (int c2 = c1 + 3; c2 <= m; c2++) {
            curr_min = prev_min = 16;
            for (int r = 5; r <= n; r++) {
                int last_row_cost = to1(r, c1 + 1, r, c2 - 1);
                int prev_4_cost = to0(r - 3, c1 + 1, r - 1, c2 - 1);
                prev_4_cost += to1(r - 4, c1 + 1, r - 4, c2 - 1);
                prev_4_cost += to1(r - 3, c1, r - 1, c1) + to1(r - 3, c2, r - 1, c2);

                curr_min = min(prev_min, prev_4_cost) + last_row_cost;
                res = min(res, curr_min);

                prev_min = curr_min;
                prev_min -= last_row_cost;
                prev_min += to0(r, c1 + 1, r, c2 - 1) + to1(r, c1, r, c1) + to1(r, c2, r, c2);
            }
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}