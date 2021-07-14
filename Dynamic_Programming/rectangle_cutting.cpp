#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(int n, int m) {
    
    if (n > m) return solve(m, n);
    if (n == m) return 0;
    if (n == 1) return m - 1;
    if (dp[n][m] != -1) return dp[n][m];

    int cand;
    dp[n][m] = INT_MAX;

    for (int x = 1; x < n; x++) {

        cand = solve(x, m) + solve(n - x, m) + 1;
        dp[n][m] = min(dp[n][m], cand);
    }
    for (int x = 1; x < m; x++) {
        
        cand = solve(n, x) + solve(n, m - x) + 1;
        dp[n][m] = min(dp[n][m], cand);
    }
    return dp[n][m];
}

int minCuts(int n, int m) {
    if (n > m) return minCuts(m, n);
    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
    return solve(n, m);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    cout << minCuts(n, m);
}