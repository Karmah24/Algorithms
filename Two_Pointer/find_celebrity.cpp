#include <bits/stdc++.h>
using namespace std;

class Solution  {
public:
    int findCelebrity(vector<vector<int>>& M, int n)  {

        int i = 0, j = n - 1;
        while (i < j) {

            if (M[i][j] == 1) i++;
            else j--;
        }
        for (j = 0; j < n; j++) {
            if (i == j) continue;
            if (M[i][j] == 1 || M[j][i] == 0) return -1;
        }
        return i;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> M[i][j];
    }
    Solution obj;
    cout << obj.findCelebrity(M, n);
}