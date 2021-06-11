#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    int solve(string& s1, string& s2, int i, int j) {

        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) return dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1);
        return dp[i][j] = max(solve(s1, s2, i - 1, j), solve(s1, s2, i, j - 1));
    }
public:
    int lcsMem(string s1, string s2, int n, int m) {

        dp = vector<vector<int>>(n, vector<int>(m, -1));
        return solve(s1, s2, n - 1, m - 1);
    }
    int lcsTab(string s1, string s2, int n, int m) {

        int dp[2][m + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[1][j] = dp[0][j - 1] + 1;
                }
                else dp[1][j] = max(dp[1][j - 1], dp[0][j]);
            }
            for (int k = 0; k <= m; k++) dp[0][k] = dp[1][k];
        }
        return dp[0][m];
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int n, m;
    string s1, s2;
    cin >> n >> m;
    cin >> s1 >> s2;
    Solution obj;
    cout << obj.lcsMem(s1, s2, n, m);
}