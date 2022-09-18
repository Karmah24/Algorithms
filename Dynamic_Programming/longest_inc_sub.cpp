#include<bits/stdc++.h>
using namespace std;

int lisDP(vector<int> &arr) {

    int n = arr.size();
    vector<int> dp(n, 1);
    int res = 1;
    for (int i = 1; i < n ; i++) {
        for (int j = 0; j < i; j++) {

            if (arr[i] > arr[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
                res = max(res, dp[i]);
            }
        }
    }
    return res;
}
int LIS_bin_search(vector<int>& arr) {

    vector<int> lis;
    for (auto &e: arr)  {

        auto itr = lower_bound(lis.begin(), lis.end(), e);
        if (itr == lis.end()) lis.push_back(e);
        else *itr = e;
    }
    cout << lis.size();
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << LIS_bin_search(arr);
}