#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    bool solve(int arr[], int n, int W) {

        if (W == 0) return true;
        if (n < 0 || W < 0) return false;
        if (dp[n][W - 1] != -1) return dp[n][W - 1];


        return dp[n][W - 1] = solve(arr, n - 1, W - arr[n]) || solve(arr, n - 1, W);
    }
public:
    int equalPartition(int n, int arr[]) {
        
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];
        if (sum % 2 != 0) return false;
        sum /= 2;       

        dp = vector<vector<int>>(n, vector<int>(sum, - 1));
        
        return solve(arr, n - 1, sum);
    }

    bool equalPartitionTab(int n, int arr[]) {

        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];
        if (sum % 2 != 0) return false;
        sum /= 2;

        bool dp[2][sum + 1];
        memset(dp[0], 0, sizeof(dp[0]));
        dp[0][0] = true;
        dp[1][0] = true;

        for (int i = 0; i < n; i++) {

            for (int j = 1; j <= sum; j++) {
                if (j < arr[i]) dp[1][j] = dp[0][j];
                else dp[1][j] = dp[0][j] || dp[0][j - arr[i]];
            }
            for (int k = 1; k <= sum; k++) dp[0][k] = dp[1][k];
        }
        return dp[1][sum];
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.equalPartitionTab(n, arr);
}