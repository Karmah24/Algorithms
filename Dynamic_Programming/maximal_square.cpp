#include <bits/stdc++.h>
using namespace std;

int maximalSquare(int R, int C, vector<vector<int>> &mat) {

    vector<vector<int>> dp(R, vector<int>(C, 0));

    int res = 0;
    for (int i = R - 1; i >= 0; i--) {

        for (int j = C - 1; j >= 0; j--) {

            if (mat[i][j] == 0) continue;

            int right = j == C - 1 ? 0 : dp[i][j + 1];
            int down = i == R - 1 ? 0 : dp[i + 1][j];
            int diag = (i == R - 1 || j == C - 1) ? 0 : dp[i + 1][j + 1];
            dp[i][j] = min({right, down, diag}) + 1;
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> M[i][j];
    }
    cout << maximalSquare(n, m, M);
}