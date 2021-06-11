#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    int solve(int e, int f) {

        if (dp[e][f] != -1) return dp[e][f];
        if (f == 1 || f == 0) return f;
        if (e == 1) return f;

        dp[e][f] = INT_MAX;
        for (int i = 1; i < f; i++) {

            int cand = max(solve(e - 1, i - 1), solve(e, f - i));
            dp[e][f] = min(dp[e][f], cand); 
        }
        return ++dp[e][f];
    }
public:
    int eggDrop(int n, int k) {
        
        dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
        return solve(n, k);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    Solution obj;
    cout << obj.eggDrop(n, k);
}
