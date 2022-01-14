#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    
    int lcs(string& s1, string& s2, int i, int j) {
        
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s1[i] == s2[j]) return dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1);
        return dp[i][j] = max(lcs(s1, s2, i - 1, j), lcs(s1, s2, i, j - 1));
    }
public:
    int scs(string X, string Y, int n, int m) {
        
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        return (m + n) - lcs(X, Y, n - 1, m - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    Solution obj;
    cout << obj.scs(s1, s2, n, m);
}