#include <bits/stdc++.h>
using namespace std;

class Solution {
    int N;
    void getPaths(int i, int j, vector<vector<int>>& m, string& path, vector<string>& paths) {

        if (i < 0 || j < 0 || i == N || j == N || m[i][j] == 0) return;
        if (i == N - 1 && j == N - 1) {
            paths.push_back(path);
            return;
        }
        m[i][j] = 0;

        path.push_back('D');
        getPaths(i + 1, j, m, path, paths);
        path.pop_back();
        path.push_back('L');
        getPaths(i, j - 1, m, path, paths);
        path.pop_back();
        path.push_back('R');
        getPaths(i, j + 1, m, path, paths);
        path.pop_back();
        path.push_back('U');
        getPaths(i - 1, j, m, path, paths);
        path.pop_back();

        m[i][j] = 1;
    }
public:
    vector<string> findPaths(vector<vector<int>>& m, int n) {

        N = n;
        vector<string> paths;
        string path = "";
        getPaths(0, 0, m ,path, paths);
        return paths;
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
    for (string str: obj.findPaths(m, n)) cout << str << ' ';
}
