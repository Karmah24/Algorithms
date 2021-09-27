#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> perimeter_edge(vector<vector<int>>& matrix, int level, vector<int>& res) {

        int sR, sC, eR, eC;
        sR = sC = 0 + level;
        eR = matrix.size() - 1 - level, eC = matrix[0].size() - 1 - level;

        for (int c = sC; c <= eC; c++)
            res.push_back(matrix[sR][c]);
        for (int r = sR + 1; r <= eR; r++)
            res.push_back(matrix[r][eC]);
        if (sR < eR)
            for (int c = eC - 1; c >= sC; c--)
                res.push_back(matrix[eR][c]);
        if (sC < eC)
            for (int r = eR - 1; r > sR; r--)
                res.push_back(matrix[r][sC]);
        if (level + 1 >= eR || level + 1 >= eC)
            return res;
        return perimeter_edge(matrix, level + 1, res);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        return perimeter_edge(matrix, 0, res);
    }
};

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    Solution obj;
    for (int e: obj.spiralOrder(a)) cout << e << " ";
}