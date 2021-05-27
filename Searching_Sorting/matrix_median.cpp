#include <bits/stdc++.h>
using namespace std;

class Solution {
    int allLess(vector<vector<int>>& mat, int x) {
        
        int res = 0;
        for (auto& v: mat) {
            res += upper_bound(v.begin(), v.end(), x) - v.begin();
        }
        return res;
    }
public:
    int findMedian(vector<vector<int>>& mat) {

        // n * m is odd
        int n = mat.size(), m = mat[0].size();
        int l = 1, r = INT_MAX - 1, res;

        while (l <= r) {
            int mid = (l + r) / 2;
            int lo = allLess(mat, mid), req = (n * m / 2) + 1;

            if (lo >= req) {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> mat[i][j];
    }
    Solution obj;
    cout << obj.findMedian(mat);
}