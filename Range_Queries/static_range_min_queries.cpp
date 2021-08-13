#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
const int N = 18, M = 2e5;
//=======================

int dp[N][M];

void build(vector<int> &arr) {

    int m = arr.size();
    int n = floor(log2(m));
    for (int i = 0; i < m; i++) {
        dp[0][i] = arr[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
        }
    }
}
int getMin(int l, int r) {
    int p = floor(log2(r - l + 1));
    int k = 1 << p;
    return min(dp[p][l], dp[p][r - k + 1]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(arr);

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << getMin(l - 1, r - 1) << ln;
    }
    return 0;
}