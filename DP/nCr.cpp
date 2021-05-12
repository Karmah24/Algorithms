#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
#define ll long long

const int mod = int(1e9 + 7);
//=======================

class Solution {
    int dp[1001][801];

    int solve(ll n, ll r) {
        if (dp[n][r] != -1) return dp[n][r];

        if (n == r || r == 0) return 1;
        if (r == 1) return n;

        dp[n][r] = ((solve(n - 1, r - 1)) % mod + (solve(n - 1, r)) % mod) % mod;
        return dp[n][r];
    }
public:
    int nCr(int n, int r) {
        fori (i, n + 1) fori (j, r + 1) dp[i][j] = -1;
        return solve(n, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, r;
    cin >> n >> r;
    Solution obj;
    cout << obj.nCr(n, r);
}
