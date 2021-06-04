#include<bits/stdc++.h>
using namespace std;

const int N = 1001;

int dpMem[N][N];

int lcsMem(string& s1, string& s2, int i, int j) {

    if (i < 0 || j < 0) return 0;
    if (dpMem[i][j] != -1) return dpMem[i][j];

    if (s1[i] == s2[j]) return dpMem[i][j] = 1 + lcsMem(s1, s2, i - 1, j - 1);

    return dpMem[i][j] = max(lcsMem(s1, s2, i - 1, j), lcsMem(s1, s2, i, j - 1));
}

int lcsTab(string s1, string s2, int x, int y) {

    int dp[2][y + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= x; i++) {
        
        for (int j = 1; j <= y; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[1][j] = dp[0][j - 1] + 1;
            }
            else dp[1][j] = max(dp[1][j - 1], dp[0][j]);
        }
        for (int k = 0; k <= y; k++) dp[0][k] = dp[1][k];
    }
    return dp[0][y];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int n, m;
    string s1, s2;
    cin >> n >> m;
    cin >> s1 >> s2;
    // memset(dpMem, -1, sizeof dpMem);
    // cout << lcsMem(s1, s2, n - 1, m - 1) << endl;
    cout << lcsTab(s1, s2, n, m) << endl;
}