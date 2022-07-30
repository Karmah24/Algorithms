#include<bits/stdc++.h>
using namespace std;

int lisDP(vector<int> &arr) {

    int n = arr.size();
    vector<int> dp(n, 1);
    int res = 1;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] >= arr[j]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
            res = max(res, dp[i]);
        }
    }
    return res;
}
int LIS_bin_search(vector<int>& arr) {
    
    int n = arr.size(), res = 1;
    vector<int> lis;
    
    for (int i = 0; i < n; i++) {
        
        int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        if (pos < lis.size()) lis[pos] = arr[i];
        else lis.push_back(arr[i]);
        
    }
    return lis.size(); 
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