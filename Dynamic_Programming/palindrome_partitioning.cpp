#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<bool>> P;
    vector<vector<int>> dp;

    void getPalindromes(string& s) {
        int n = s.size();
        P = vector<vector<bool>>(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            P[i][i] = true;
            for (int j = i + 1; j < n; j++) {
                if (s[i] != s[j]) continue;

                if (j - i == 1 || P[i + 1][j - 1]) P[i][j] = true;
            }
        }
    }
    int solve(string& s, int l, int r) {

        if (P[l][r]) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        dp[l][r] = r - l;
        for (int i = l; i < r; i++) {

            int sub = solve(s, l, i) + solve(s, i + 1, r);
            dp[l][r] = min(dp[l][r], sub + 1);
        }
        return dp[l][r];
    }
public:
    int minCutMcm(string s) {

        getPalindromes(s);
        dp = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        return solve(s, 0, s.size() - 1);
    }
    int minCut(string s) {

        getPalindromes(s);
        int n = s.size();
        int cuts[n];
        for (int& e: cuts) e = 0;

        for (int i = 1; i < n; i++) {

            if (P[0][i]) continue;

            cuts[i] = cuts[i - 1] + 1;
            if (cuts[i] == 1) continue;

            for (int j = 1; j < i; j++) {
                if (P[j][i]) {
                    cuts[i] = min(cuts[i], cuts[j - 1] + 1);
                }
            }
        }
        return cuts[n - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    Solution obj;
    string s;
    cin >> s;
    cout << obj.minCutMcm(s);
}