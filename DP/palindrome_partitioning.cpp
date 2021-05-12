#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool isPalindrome(string& s, int l, int h, vector<vector<bool>>& P) {
        if (h - l == 1 && s[l] == s[h]) return true;
        if (P[l+ 1][h - 1] && s[l] == s[h]) return true;
        return false;
    }
public:
    int minCut(string s) {
        int n = s.size();
        // vector<vector<bool>> dp(n, vector<bool>(n, false));
        // for (int i = n - 1; i >= 0; i--) {
        //     dp[i][i] = true;
        //     for (int j = i + 1; j < n; j++) dp[i][j] = isPalindrome(s, i, j, dp);
        // }

        bool P[n][n];
        for (int i = n - 1; i >= 0; i--) {
            P[i][i] = true;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i == 1 || P[i + 1][j - 1]) {
                        P[i][j] = true;
                        continue;
                    }
                }
                P[i][j] = false;
            }
        }
        int cuts[n];
        for (int& e: cuts) e = 0;
        for (int j = 1; j < n; j++) {
            if (P[0][j]) continue;
            cuts[j] = cuts[j - 1] + 1;
            if (cuts[j] == 1) continue;
            for (int i = 1; i < j; i++) {
                if (P[i][j]) {
                    cuts[j] = min(cuts[j], cuts[i - 1] + 1);
                    // break;
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
    cout << obj.minCut(s);
}
