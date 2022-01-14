#include <bits/stdc++.h>
using namespace std;

vector<int> moneySums(int coins[], int n) {

    unordered_set<int> dp[2];
    dp[0].insert(0);
    dp[1].insert(0);

    for (int i = 0; i < n; i++) {

        for (int e: dp[0]) dp[1].insert(e + coins[i]);
        dp[0] = unordered_set<int>(dp[1].begin(), dp[1].end());
    }
    vector<int> res(dp[0].begin(), dp[0].end());
    sort(res.begin(), res.end());
    res = vector<int>(res.begin() + 1, res.end());
    return res;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> res = moneySums(arr, n);
    cout << res.size() << '\n';
    for (int e: res) cout << e << " ";
}