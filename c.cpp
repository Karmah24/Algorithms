#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(int l, int r, string s) {

    if (l > r) return 0;
    if (l == r) return 1;
    if (dp[l][r] != -1) return dp[l][r];

    int res = 1 + solve(l + 1, r, s);

    for (int i = l + 1; i <= r; i++) {

        if (s[l] == s[i]) {
            res = min(res, solve(l + 1, i - 1, s) + solve(i, r, s));
        }
    }
    return dp[l][r] = res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        string str;
        cin.ignore();
        getline(cin, str);
        std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
        str.erase(end_pos, str.end());
        n = str.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        cout << solve(0, n - 1, str) << '\n';
    }
}