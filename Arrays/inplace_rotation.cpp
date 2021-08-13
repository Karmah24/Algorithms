#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     
        // Tranposed + Reversed = Rotated
        int n = matrix.size();

        // Transpose
        for (int i = 0; i < n; i++) {    
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse
        for (auto &row: matrix) {
            int i = 0, j = n - 1;
            while (i < j) {
                swap(row[i++], row[j--]);
            }
        }
    }
};