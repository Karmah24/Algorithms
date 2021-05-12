#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
typedef vector<int>		vi;
typedef vector<vi>		vvi;
//=======================

class Solution {
public:
    vi solve(vvi matrix, int n, int m) {
        int i = 0, j = 0;
        bool down = true;
        vi res{matrix[0][0]};
        while (i != n - 1 || j != m - 1) {
            if (down) {
                if (i == n - 1) {
                    j++;
                    down = false;
                }
                else if (j == 0) {
                    i++;
                    down = false;
                }
                else if (i + 1 < n && j - 1 >= 0) {
                    i++; j--;
                }
                else break;
                res.push_back(matrix[i][j]);
            }
            else {
                if (j == n - 1) {
                    i++;
                    down = true;
                }
                else if (i == 0) {
                    j++;
                    down = true;
                }
                else if (i - 1 >= 0 && j + 1 < n) {
                    i--; j++;
                }
                else break;
                res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vvi matrix(n, vi(m));
        fori (i, n) fori (j, m) cin >> matrix[i][j];
        Solution obj;
        for (int e: obj.solve(matrix, n, m)) cout << e << ' ';
    }
}

