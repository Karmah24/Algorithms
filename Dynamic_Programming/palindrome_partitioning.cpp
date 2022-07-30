#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> P;
vector<int> dp;

void getPalindromes(string& s) {
    int n = s.size();
    P = vector<vector<bool>>(n, vector<bool>(n, true));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            P[i][j] = s[i] == s[j] && P[i + 1][j - 1];
        }
    }
}
int solve(int l, string& s) {

    if (l == s.size()) return 0;
    if (dp[l] != -1) return dp[l];

    dp[l] = INT_MAX;
    for (int r = l; r < s.size(); r++) {
        
        if (!P[l][r]) continue;
        dp[l] = min(dp[l], 1 + solve(r + 1, s));
    }
    return dp[l];
}
int minCutMcm(string s) {

    getPalindromes(s);
    dp.assign(s.size(), -1);
    return solve(0, s) - 1;
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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;
    cout << minCutMcm(s);
}