#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)

//=======================
int dp[101][101];

int solve(string s1, string s2, int i1, int i2) {
    if (i1 == -1)
        return i2 + 1;
    if (i2 == -1)
        return i1 + 1;    
    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    if (s1[i1] == s2[i2])
        dp[i1][i2] = solve(s1, s2, i1 - 1, i2 - 1);
    else 
        dp[i1][i2] = min({solve(s1, s2, i1 - 1, i2 - 1), solve(s1, s2, i1, i2 - 1), solve(s1, s2, i1 - 1, i2)}) + 1;
    
    return dp[i1][i2];

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    loop (i, n) loop (j, m) dp[i][j] = -1;

    cout << solve(s1, s2, n - 1, m - 1);
}