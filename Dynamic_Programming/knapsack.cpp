#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    int solve(int wt[], int val[], int W, int n) {

        if (n < 0 || W <= 0) return 0;
        if (dp[n][W - 1] != -1) return dp[n][W - 1];

        int ifin, ifout = solve(wt, val, W, n - 1);
        ifin = W < wt[n] ? 0: solve(wt, val, W - wt[n], n - 1) + val[n];

        return dp[n][W - 1] = max(ifin, ifout);
    }
public:
    int knapSackMem(int W, int wt[], int val[], int n) {

        dp = vector<vector<int>>(n, vector<int>(W, -1));
        return solve(wt, val, W, n - 1);
    }

    int knapSackTab(int W, int wt[], int val[], int n) {

        int dp[2][W + 1];
        memset(dp[0], 0, sizeof(dp[0]));

        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j <= W; j++) {
                if (wt[i] > j) dp[1][j] = dp[0][j];
                else {
                    dp[1][j] = max(dp[0][j], dp[0][j - wt[i]] + val[i]);
                }
            }
            for (int k = 0; k <= W; k++) dp[0][k] = dp[1][k];
        }
        return dp[1][W];
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, w;
    cin >> n >> w;
    int val[n], wt[n];
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> wt[i];
    Solution obj;
    cout << obj.knapSackMem(w, wt, val, n);
}
