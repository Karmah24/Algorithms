#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
typedef vector<int>		vi;
typedef vector<vi>		vvi;
//=======================

class Solution {
    int dp[502][502];
    int solve(int l, int r, int arr[]) {

        if (dp[l][r] != -1) return dp[l][r];

        if (r - l < 2) return 0;

        dp[l][r] = INT_MAX;
        for (int i = l + 1; i < r; i++) {
            int subCost = solve(l, i, arr) + solve(i, r, arr);
            int totCost = subCost + (arr[l] * arr[i] * arr[r]);
            dp[l][r] = min(dp[l][r], totCost);
        }
        return dp[l][r];
    }
public:
    int matrixMultiplication(int n, int arr[]) {
        memset(dp, -1, sizeof dp);
        return solve(0, n - 1, arr);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int arr[n];
        fori (i, n) cin >> arr[i];
        Solution obj;
        cout << obj.matrixMultiplication(n, arr) << endl;
    }
}
