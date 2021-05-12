#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
typedef vector<int>     vi;
typedef vector<vi>		vvi;
//=======================

class Solution {
    void dfs(int i, int j, int n, vector<vector<int>> &m,vector<vector<bool>>& vis, 
        vector<string>& paths, string& path) {

        if (m[i][j] == 0) return;
        if (i == n - 1 && j == n - 1) {
            paths.push_back(path);
            return;
        }
        vis[i][j] = true;

        if (i < n - 1 && !vis[i + 1][j]) {
            path.push_back('D');
            dfs(i + 1, j, n, m, vis, paths, path);
            path.pop_back();
        }
        if (j > 0 && !vis[i][j - 1]) {
            path.push_back('L');
            dfs(i, j - 1, n, m, vis, paths, path);
            path.pop_back();
        }
        if (j < n - 1 && !vis[i][j + 1]) {
            path.push_back('R');
            dfs(i, j + 1, n, m, vis, paths, path);
            path.pop_back();
        }
        if (i > 0 && !vis[i - 1][j]) {
            path.push_back('U');
            dfs(i - 1, j, n, m, vis, paths, path);
            path.pop_back();
        }
        vis[i][j] = false;
    }
    public:
    vector<string> findPaths(vector<vector<int>> &m, int n) {
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<string> paths;
        string path = "";
        dfs(0, 0, n, m, vis, paths, path);
        return paths;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vvi m(n, vi(n));
    fori (i, n) fori (j, n) cin >> m[i][j];
    Solution obj;
    for (string str: obj.findPaths(m, n)) cout << str << ' ';
}
