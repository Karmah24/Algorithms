#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<double>> dp;
    double solve(int n, int W, vector<vector<int>> &arr) {

        if (n < 0) return 0;
        if (dp[n][W] != -1) return dp[n][W];

        dp[n][W] = 0;
        for (int i = 0; i <= W; i++) {

            double passRatio = ((double)arr[n][0] + i) / (arr[n][1] + i);
            dp[n][W] = max(dp[n][W], solve(n - 1, W - i, arr) + passRatio);
        }
        return dp[n][W];
    }
    double ratio(int a, int b) {
        return (double)a / b;
    }
public:
    double maxAverageRatio1(vector<vector<int>>& classes, int extraStudents) {

        int n = classes.size();
        dp = vector<vector<double>>(n, vector<double>(extraStudents + 1, -1));

        return solve(n - 1, extraStudents, classes) / n;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pair<double, int>> pq;
        
        double res = 0;
        for (int i = 0; i < classes.size(); i++) {
            auto &cl = classes[i];
            pq.push({ratio(cl[0] + 1, cl[1] + 1) - ratio(cl[0], cl[1]), i});
            res += ratio(cl[0], cl[1]);
        }
        while (extraStudents--) {
            
            auto tp = pq.top();
            pq.pop();
            res += tp.first;
            auto &cl = classes[tp.second];
            cl[0]++, cl[1]++;
            pq.push({ratio(cl[0] + 1, cl[1] + 1) - ratio(cl[0], cl[1]), tp.second});
        }
        return res / classes.size();
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> classes(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> classes[i][0] >> classes[i][1];
    }
    Solution obj;
    cout << obj.maxAverageRatio(classes, k);
}