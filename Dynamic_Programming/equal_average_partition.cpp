#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<vector<int>>> dp;

    bool solve(vector<int>& arr, int n, int W, int x, unordered_set<int>& res) {

        if (W == 0 && x == 0) return true;
        if (n < 0 || W < 0 || x == 0) return false;
        if (dp[n][W][x] != -1) return dp[n][W][x];

        res.insert(n);
        if (solve(arr, n - 1, W - arr[n], x - 1, res)) return dp[n][W][x] = 1;
        res.erase(n);

        return dp[n][W][x] = solve(arr, n - 1, W, x, res);
    }
public:
    vector<vector<int>> avgset(vector<int>& arr) {
        
        int n = arr.size(), sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];

        sort(arr.begin(), arr.end(), greater<int>());
        vector<vector<int>> res(2);

        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(sum + 1, vector<int>(n, -1)));
        unordered_set<int> idx;

        for (int x = 1; x < n; x++) {
            if ((sum * x) % n != 0) continue;
            int W = (sum  * x) / n;
            idx.clear();
            if (solve(arr, n - 1, W, x, idx)) break;
        }
        if (idx.size() == 0) return {};

        for (int e: idx) {
            res[0].push_back(arr[e]);
        }
        for (int i = 0; i < n; i++) {
            if (idx.find(i) == idx.end()) res[1].push_back(arr[i]);
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
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
    for (auto& v: obj.avgset(arr)) {
        for (int e: v) cout << e << " ";
        cout << endl;
    }
}