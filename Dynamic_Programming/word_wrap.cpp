#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    int n;
    vector<ll> dp;

    ll solve(int l, ll k, vector<int> &arr) {

        if (dp[l] != -1) return dp[l];

        dp[l] = LLONG_MAX;
        ll inLine = -1, lineCost;

        for (int i = l; i < n; i++) {

            inLine += arr[i] + 1;
            if (inLine > k) break;
            lineCost = pow(k - inLine, 2);
            if (i == n - 1) dp[l] = 0;
            else dp[l] = min(dp[l], lineCost + solve(i + 1, k, arr));
        }
        return dp[l];
    }
public:
    int solveWordWrap(vector<int>arr, int k) {

        n = arr.size();
        dp = vector<ll>(n, -1);
        return solve(0, k, arr);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.solveWordWrap(arr, k);
}