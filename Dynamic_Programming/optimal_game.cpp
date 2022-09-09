#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll maxScore(int arr[], int n) {

    ll dp[n][n];
    for (int i = 0; i < n - 1; i++) {
        dp[i][i] = arr[i];
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }
    dp[n - 1][n - 1] = arr[n - 1];

    for (int i = n - 3; i >= 0; i--) {

        for (int j = i + 2; j < n; j++) {

            ll cand1 = min(dp[i + 2][j], dp[i + 1][j - 1]) + arr[i];
            ll cand2 = min(dp[i + 1][j - 1], dp[i][j - 2]) + arr[j];
            dp[i][j] = max(cand1, cand2);
        }
    }
    return dp[0][n - 1];
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << maxScore(arr, n);
}