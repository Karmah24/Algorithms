#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    vector<vector<ll>> dp;
    
    ll solve(int arr[], int n, int W) {
        
        if (W == 0) return 1;
        if (n < 0) return 0;
        if (dp[n][W - 1] != -1) return dp[n][W - 1];

        ll ifin, ifout = solve(arr, n - 1, W);
        ifin = W < arr[n] ? 0 : solve(arr, n, W - arr[n]);

        return dp[n][W - 1] = ifin + ifout;
    }
public:
    ll count(int S[], int m, int n) {
        
        dp = vector<vector<ll>>(m, vector<ll>(n, -1));
        return solve(S, m - 1, n);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    int S[n];
    for (int i = 0; i < n; i++)  cin >> S[i];
    Solution obj;
    cout << obj.count(S, m, n);
}