#include<bits/stdc++.h>
using namespace std;

int lisDP(int n, int arr[]) {

    int dp[n];
    for (int i = 0; i < n; i++) dp[i] = 1;
    int res = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {

            if (arr[i] > arr[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
                res = max(res, dp[i]);
            }
        }
    }
    return res;
}
int lis(int n, int arr[]) {

    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << lis(n, arr);
}