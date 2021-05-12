#include <iostream>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    int mat[n][3];
    loop (i, n) loop (j, 3) cin >> mat[i][j];

    if (n == 1) {
        cout << max(max(mat[0][0], mat[0][1]), mat[0][2]);
        return 0;
    }

    int dp[2][3];
    dp[0][0] = mat[0][0], dp[0][1] = mat[0][1], dp[0][2] = mat[0][2];
    for (int i = 1; i < n; i++) {
        dp[1][0] = mat[i][0] + max(dp[0][1], dp[0][2]);
        dp[1][1] = mat[i][1] + max(dp[0][0], dp[0][2]);
        dp[1][2] = mat[i][2] + max(dp[0][0], dp[0][1]);
        dp[0][0] = dp[1][0], dp[0][1] = dp[1][1], dp[0][2] = dp[1][2];
    }
    cout << max(max(dp[1][0], dp[1][1]), dp[1][2]);
}