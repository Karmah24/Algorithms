#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> dp;

// int solve(int n, int W, int price[], int pages[]) {

//     if (n < 0 || W == 0) return 0;
//     if (dp[n][W] != -1) return dp[n][W];

//     int ifin, ifout = solve(n - 1, W, price, pages);
//     ifin = W < price[n] ? 0 : pages[n] + solve(n - 1, W - price[n], price, pages);
//     return dp[n][W] = max(ifin, ifout);
// }

int maxPages(int n, int x, int price[], int pages[]) {

    // dp = vector<vector<int>>(n, vector<int>(x + 1, -1));
    // return solve(n - 1, x, price, pages);

    int dp[2][x + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {

        for (int j = 1; j <= x; j++) {
            
            int ifout = dp[0][j];
            int ifin = j < price[i] ? 0 : dp[0][j - price[i]] + pages[i];
            dp[1][j] = max(ifin, ifout);
        }
        for (int j = 1; j <= x; j++) dp[0][j] = dp[1][j];
    }
    return dp[0][x];
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, x;
    cin >> n >> x;
    int price[n], pages[n];
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];
    cout << maxPages(n, x, price, pages);
}