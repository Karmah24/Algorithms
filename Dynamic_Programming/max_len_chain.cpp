#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // auto comp = [](vector<int> a, vector<int> b){
        //     return a[0] < b[0];
        // };
        // sort(pairs.begin(), pairs.end(), comp);
        // int res = 0, n = pairs.size();
        // int dp[n];
        // for (int& e: dp) e = 1;
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (pairs[i][0] > pairs[j][1] && dp[i] <= dp[j]) {
        //             dp[i] = dp[j] + 1;
        //         }
        //         res = max(res, dp[i]);
        //     }
        // }
        // return res;
        auto comp = [](vector<int>a, vector<int>b){
            return a[1] < b[1];
        };
        sort(pairs.begin(), pairs.end(), comp);
        int cur = INT_MIN, res = 0;
        for (auto pair: pairs) if (cur < pair[0]) {
            cur = pair[1];
            res++;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    Solution obj;
    int n;
    cin >> n;
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> pairs[i][0];
        cin >> pairs[i][1];
    }
    cout << obj.findLongestChain(pairs) << endl;
}
