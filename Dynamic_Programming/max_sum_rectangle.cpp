#include <bits/stdc++.h>
using namespace std;

class Solution {
    int kadane(vector<int> &arr) {

        int n = arr.size();
        int curr = arr[0], res = arr[0];

        for (int i = 1; i < n; i++) {
            curr = max(arr[i], arr[i] + curr);
            res = max(res, curr);
        }
        return res;
    }
  public:
    int maximumSumRectangle(int row, int col, vector<vector<int>> M) {
        
        int res = INT_MIN;
        vector<int> sub(col, 0);

        for (int l = 0; l < row; l++) {
            for (int r = l; r < row; r++) {

                for (int i = 0; i < col; i++) sub[i] += M[r][i];
                res = max(res, kadane(sub));
            }
            for (int &e: sub) e = 0;
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
    vector<vector<int>> M(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> M[i][j];
    }
    Solution obj;
    cout << obj.maximumSumRectangle(n, m, M);
}