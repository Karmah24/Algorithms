#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, m;
    vector<vector<int>> dp;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int dfs(int r, int c, vector<vector<int>> &mat) {

        if (dp[r][c] != -1) return dp[r][c];
        dp[r][c] = 0;
        for (int i = 0; i < 4; i++) {
            int r1 = r + dy[i], c1 = c + dx[i];
            if (r1 == n || c1 == m || r1 < 0 || c1 < 0) continue;
            if (mat[r1][c1] > mat[r][c]) {
                dp[r][c] = max(dp[r][c], dfs(r1, c1, mat));
            }
        }
        return ++dp[r][c];
    }
public:
    // dfs + memoization
    int longestIncreasingPath(vector<vector<int>> &mat) {

        n = mat.size(), m = mat[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        int res = 1;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                res = max(res, dfs(r, c, mat));
            }
        }
        return res;
    }
    // using topological sort
    int longestIncreasingPath1(vector<vector<int>> &mat) {

        n = mat.size(), m = mat[0].size();
        vector<vector<int>> inDegree(n, vector<int>(m, 0));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {

                for (int i = 0; i < 4; i++) {
                    int r1 = r + dy[i], c1 = c + dx[i];
                    if (r1 == n || r1 < 0 || c1 == m || c1 < 0) continue;
                    if (mat[r1][c1] > mat[r][c]) inDegree[r1][c1]++;
                }
            }
        }
        queue<pair<int, int>> q;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (inDegree[r][c] == 0) q.push({r, c});
            }
        }
        int lvl = 0;
        while (!q.empty()) {

            lvl++;
            int size = q.size();
            while (size--) {

                auto [r, c] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int r1 = r + dy[i], c1 = c + dx[i];
                    if (r1 == n || r1 < 0 || c1 == m || c1 < 0) continue;
                    if (mat[r1][c1] > mat[r][c]) {
                        if (--inDegree[r1][c1] == 0) q.push({r1, c1});
                    }
                }
            }
        }
        return lvl;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> mat[i][j];
    }
    Solution obj;
    cout << obj.longestIncreasingPath(mat);
}