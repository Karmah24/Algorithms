#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    int solve(int arr[], int n, int W) {

        if (n < 0 || W == 0) return 0;
        if (dp[n][W - 1] != -1) return dp[n][W - 1];

        int ifin, ifout = solve(arr, n - 1, W);
        ifin = W < n + 1 ? 0 : solve(arr, n, W - n - 1) + arr[n];

        return dp[n][W - 1] = max(ifin, ifout);
    }
  public:
    int cutRod(int price[], int n) {

        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return solve(price, n - 1, n);
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
    cout << obj.cutRod(arr, n);
}