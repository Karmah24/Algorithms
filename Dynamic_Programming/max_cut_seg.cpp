#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeTheCuts(int n, int x, int y, int z) {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        int seg[3] = {x, y, z};

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {

                if (i < seg[j]) continue;

                if (dp[i - seg[j]] != 0 || i == seg[j]) {
                    dp[i] = max(dp[i], dp[i - seg[j]] + 1);
                }
            }
        }
        return dp[n];
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, x, y, z;
    cin >> n >> x >> y >> z;
    Solution obj;
    cout << obj.maximizeTheCuts(n, x, y, z);
}