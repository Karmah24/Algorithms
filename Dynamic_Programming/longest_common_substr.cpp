#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int res;

int lcs(string &s1, string &s2, int i, int j) {

    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    if (s1[i] == s2[j]) {
        dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1);
        res = max(res, dp[i][j]);
    }
    else dp[i][j] = 0;
    lcs(s1, s2, i - 1, j);
    lcs(s1, s2, i, j - 1);
    return dp[i][j];
}

int longestCommonSubstr(string s1, string s2, int n, int m) {

    dp.assign(n, vector<int>(m, -1));
    res = 0;
    lcs(s1, s2, n - 1, m - 1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubstr(s1, s2, s1.size(), s2.size());
}