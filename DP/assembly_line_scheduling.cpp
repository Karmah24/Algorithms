#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
typedef vector<int>		vi;
//=======================

class Solution {
public:
    int solve(int n, vi line1, vi line2, vi cost1, vi cost2) {
        
        int dp[2][n];
        dp[0][0] = line1[0];
        dp[1][0] = line2[0];


        for (int i = 1; i < n; i++) {
            dp[0][i] = min(dp[0][i - 1] + line1[i], dp[1][i - 1] + cost2[i - 1] + line2[i]);
            dp[1][i] = min(dp[1][i - 1] + line2[i], dp[0][i - 1] + cost1[i - 1] + line1[i]);
        }
        return min(dp[0][n - 1] + line1[n + 1] + line1[n], dp[1][n - 1] + line2[n + 1] + line2[n]);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vi line1(n + 2), line2(n + 2), cost1(n - 1), cost2(n - 1);
    loop (i, n + 2) cin >> line1[i];
    loop (i, n + 2) cin >> line2[i];
    loop (i, n - 1) cin >> cost1[i];
    loop (i, n - 1) cin >> cost2[i];
    Solution obj;
    cout << obj.solve(n, line1, line2, cost1, cost2);
}
