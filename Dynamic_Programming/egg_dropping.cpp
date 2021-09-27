#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    int solve1(int e, int f) {

        if (dp[e][f] != -1) return dp[e][f];
        if (f == 1 || f == 0 || e == 1) return f;

        dp[e][f] = f;
        for (int i = 1; i <= f; i++) {

            int cand = max(solve(e - 1, i - 1), solve(e, f - i));
            dp[e][f] = min(dp[e][f], cand); 
        }
        return ++dp[e][f];
    }
    int solve(int e, int f) {

        if (e == 1 || f == 0 || f == 1) return f;
        if (dp[e][f] != -1) return dp[e][f];

        int lo = 1, hi = f;
        while (lo + 1 < hi) {

            int mid = (lo + hi) / 2;
            int a = solve(e - 1, mid - 1), b = solve(e, f - mid);

            if (a == b) lo = hi = mid;
            else if (a < b) lo = mid;
            else hi = mid;
        }
        int cand1 = max(solve(e - 1, lo - 1), solve(e, f - lo));
        int cand2 = max(solve(e - 1, hi - 1), solve(e, f - hi));
        return dp[e][f] = min(cand1, cand2) + 1;
    }
public:
    int eggDrop(int k, int n) {
        
        dp.assign(k + 1, vector<int>(n + 1, -1));
        return solve(k, n);
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
