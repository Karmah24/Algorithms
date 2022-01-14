#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int, int>> movs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
    vector<vector<vector<int>>> dp;

    int solve(vector<string>& board, int n, int m, int i, int j, int d, vector<vector<int>>& res) {

        if (i < 0 || j < 0 || i == n || j == m) return;
        if (dp[d][i][j] != -1) return dp[d][i][j];

        for (int k = 0; k < 7; k++) {

            int x = movs[k].first, y = movs[k].second;
            if (board[i + x][j + y] == '1') dp[k][i][j] = 1;
            else dp[d][i][j] += solve(board, n, m, i + x, j + y, k, res);
        }
    }
public:
    vector<vector<int>> queenAttack(vector<string>& board) {
        
        int n = board.size(), m = board[0].size();
        dp = vector<vector<vector<int>>>(8, vector<vector<int>>(n, vector<int>(m, -1)));

        vector<vector<int>> res(n, vector<int>(m));
        
        for (int k = 0; k < 7; k++) {
            int x = movs[k].first, y = movs[k].second;
            if (board[i + x][j + y] == '1') dp[k][i][j] = 1;
            else dp[k][i][j] = solve(board, n, m, i + x, j + y, d, res);
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<string> board(n);
    for (int i = 0; i < n; i++) cin >> board[i];
    Solution obj;
    for (auto& v: obj.queenAttack(board)) {
        for (int e: v) cout << e << " ";
        cout << endl;
    }
}