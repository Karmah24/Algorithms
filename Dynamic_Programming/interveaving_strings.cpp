#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
    
    bool solve(string& A, string& B, string& C, int i, int j, int k) {

        if (i < 0 && j < 0) return k < 0;
        if (i < 0) return B.substr(0, j + 1) == C.substr(0, k + 1);
        if (j < 0) return A.substr(0, i + 1) == C.substr(0, k + 1);

        if (dp[i][j] != -1) return dp[i][j];

        if (A[i] == C[k] && B[j] != C[k]) return dp[i][j] = solve(A, B, C, i - 1, j, k - 1);
        if (B[j] == C[k] && A[i] != C[k]) return dp[i][j] = solve(A, B, C, i, j - 1, k - 1);

        if (A[i] == B[j] && A[i] == C[k]) return dp[i][j] = solve(A, B, C, i - 1, j, k - 1) || solve(A, B, C, i, j - 1, k - 1);

        return false;
    }
public:
    bool isInterleave(string A, string B, string C) {
        
        if (A.size() + B.size() != C.size()) return false;
        dp = vector<vector<int>>(A.size(), vector<int>(B.size(), -1));
        return solve(A, B, C, A.size() - 1, B.size() - 1, C.size() - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string A, B, C;
    cin >> A >> B >> C;
    Solution obj;
    cout << obj.isInterleave(A, B, C);
}