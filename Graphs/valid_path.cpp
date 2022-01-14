#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool res = false;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    void dfs(vector<vector<bool>> &mat, int x, int y, int m, int n) {

        if (x == m - 1 && y == n - 1) {
            res = true;
            return;
        }
        mat[y][x] = 0;

        for (int i = 0; i < 8; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || ty < 0 || tx >= m || ty >= n || mat[ty][tx] == 0) continue;
            dfs(mat, tx, ty, m, n);
            if (res) return;
        }
    }
    bool inCircle(int y, int x, vector<int> &cx, vector<int> &cy, int r) {

        for (int i = 0; i < cx.size(); i++) {
            if (pow(cx[i] - x, 2) + pow(cy[i] - y, 2) <= r * r) return true;
        }
        return false;
    }
public:
    string solve(int m, int n, int k, int r, vector<int> &cx, vector<int> &cy) {
    
        vector<vector<bool>> mat(n, vector<bool>(m, 1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (inCircle(i, j, cx, cy, r)) mat[i][j] = 0;
            }
        }
        res = false;
        if (mat[0][0] && mat[n - 1][m - 1]) dfs(mat, 0, 0, m, n);
        return res ? "YES" : "NO";
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int m, n, k, r;
    cin >> m >> n >> k >> r;
    vector<int> cx(k), cy(k);
    for (int i = 0; i < k; i++) cin >> cx[i];
    for (int i = 0; i < k; i++) cin >> cy[i];
    Solution obj;
    cout << obj.solve(m, n, k, r, cx, cy);
}