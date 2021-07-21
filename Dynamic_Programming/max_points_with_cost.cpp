#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll maxPoints(vector<vector<int>>& points) {
        
        
        int n = points.size(), m = points[0].size();
        
        vector<ll> prev(m, 0), curr(m, 0);

        for (int i = 0; i < n; i++) {

            vector<ll> left(m), right(m);
            left[0] = prev[0], right[m - 1] = prev[m  - 1];
            for (int j = 1; j < m; j++) {
                left[j] = max(prev[j], left[j - 1] - 1);
            }
            for (int j = m - 2; j >= 0; j--) {
                right[j] = max(prev[j], right[j + 1] - 1);
            }
            for (int j = 0; j < m; j++) {
                curr[j] = max(left[j], right[j]) + points[i][j];
            }
            prev = curr;
        }
        ll res = 0;
        for (ll e: curr) res = max(res, e);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> points(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> points[i][j];
    }
    Solution obj;
    cout << obj.maxPoints(points);
}