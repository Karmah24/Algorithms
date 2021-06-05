#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    int solve(vector<int>& arr, int n, int W) {

        if (W < 0) return 0;
        if (n < 0) return W == 0;
        if (dp[n][W] != -1) return dp[n][W];

        return dp[n][W] = solve(arr, n - 1, W - arr[n]) + solve(arr, n - 1, W);
    }
public:
    int findTargetSumWays(vector<int>& arr, int target) {

        int sum = 0;
        for (int i = 0; i < arr.size(); i++) sum += arr[i];
        if (target > sum) return 0;
        int s = (target + sum);
        if (s % 2 != 0) return 0;
        s /= 2;

        dp = vector<vector<int>>(arr.size(), vector<int>(s + 1, -1));

        return solve(arr, arr.size() - 1, s);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int k, n;
    cin >> k >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.findTargetSumWays(arr, k);
}