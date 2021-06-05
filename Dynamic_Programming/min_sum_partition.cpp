#include <bits/stdc++.h>
using namespace std;

class Solution {
    int t;
    vector<vector<int>> dp;

    int solve(int arr[], int n, int s) {
        
        if (n < 0) return abs(t - 2 * s);
        if (dp[n][s] != -1) return dp[n][s];

        return dp[n][s] = min(solve(arr, n - 1, s), solve(arr, n - 1, s + arr[n]));
    }
public:
	int minDifference(int arr[], int n)  {
	    
	    int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];

        dp = vector<vector<int>>(n, vector<int>(sum + 1, -1));
        t = sum;
        
        return solve(arr, n - 1, 0);
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
    cout << obj.minDifference(arr, n);
}