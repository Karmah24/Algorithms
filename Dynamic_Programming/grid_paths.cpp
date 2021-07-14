#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}

vector<vector<ll>> dp;

ll solve(int i, int j, int n, vector<string> &grid) {

    if (i == n || j == n || grid[i][j] == '*') return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (i == n - 1 && j == n - 1) return 1;

    dp[i][j] = 0;
    return dp[i][j] = add(solve(i + 1, j, n, grid), solve(i, j + 1, n, grid));
}

int allPaths(int n, vector<string> &grid) {

    dp = vector<vector<ll>>(n, vector<ll>(n, -1));
    return solve(0, 0, n, grid);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    cout << allPaths(n, grid);
}