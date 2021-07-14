#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(string &s1, string &s2, int n, int m) {

    if (n == -1) return m + 1;
    if (m == -1) return n + 1;    
    if (dp[n][m] != -1) return dp[n][m];

    if (s1[n] == s2[m]) return dp[n][m] = solve(s1, s2, n - 1, m - 1);

    dp[n][m] = min({solve(s1, s2, n - 1, m - 1), solve(s1, s2, n, m - 1), solve(s1, s2, n - 1, m)}) + 1;
}

int editDistance(string &s1, string &s2) {

    dp = vector<vector<int>>(s1.size(), vector<int>(s2.size(), -1));
    return solve(s1, s2, s1.size() - 1, s2.size() - 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;
    cout << editDistance(s1, s2);
}