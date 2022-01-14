#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& arr) {

        int tsum = 0;
        for (int& e: arr) tsum += e;
        if (tsum % 3 != 0) return 0;
        int k = tsum / 3;
        
        int prefixSum = 0;
        vector<int> validPrefix;
        for (int i = 0; i < arr.size() - 2; i++) {
            prefixSum += arr[i];
            if (prefixSum == k) validPrefix.push_back(i);
        }
        sort(validPrefix.begin(), validPrefix.end());

        int suffixSum = 0, res = 0;
        for (int i = arr.size() - 1; i > 1; i--) {
            suffixSum += arr[i];
            if (suffixSum == k) {
                int x = upper_bound(validPrefix.begin(), validPrefix.end(), i - 2) - validPrefix.begin();
                res += x;
            }
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.solve(arr);
}