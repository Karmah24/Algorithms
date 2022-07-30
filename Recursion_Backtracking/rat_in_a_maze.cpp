#include <bits/stdc++.h>
using namespace std;

class Solution{
    int n;
    int dy[4] = {1, 0, 0, -1};
    int dx[4] = {0, -1, 1, 0};
    char moves[4] = {'D', 'L', 'R', 'U'};
    
    void solve(int r, int c, vector<string> &res, string &curr, vector<vector<int>> &maze) {
        
        if (r < 0 || c < 0 || r == n || c == n || maze[r][c] == 0) return;
        if (r == n - 1 && c == n - 1) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < 4; i++) {
            curr.push_back(moves[i]);
            maze[r][c] = 0;
            solve(r + dy[i], c + dx[i], res, curr, maze);
            curr.pop_back();
            maze[r][c] = 1;
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        this->n = n;
        string curr;
        vector<string> res;
        solve(0, 0, res, curr, m);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)  cin >> m[i][j];
    }
    Solution obj;
    for (string str: obj.findPath(m, n)) cout << str << ' ';
}
