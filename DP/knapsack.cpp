#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knapSack(int W, int wt[], int val[], int n) {
        int dp[2][W + 1];
        for (int& e: dp[0]) e = 0;
        
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
    Solution obj;
    int n, w;
    cin >> n >> w;
    int val[n], wt[n];
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> wt[i];
    cout << obj.knapSack(w, wt, val, n);
}
