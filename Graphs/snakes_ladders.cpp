#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    pair<int, int> getPos(int u) {
        
        int r = n - ((u - 1) / n) - 1;
        int c = (u - 1) % n;
        if (r % 2 != (n - 1) % 2) c = n - c - 1;
        return {r, c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        n = board.size();
        vector<bool> vis(n * n, false);
        queue<pair<int, int>> q;
        vis[0] = true;
        q.push({1, 0});
        while (!q.empty()) {
            
            auto[u, lvl] = q.front();
            q.pop();
            
            for (int i = 1; i <= 6; i++) {
                int v = min(n * n, u + i);
                auto[r, c] = getPos(v);
                if (board[r][c] != -1) v = board[r][c];
                if (vis[v - 1]) continue;
                
                if (v == n * n) return lvl + 1;
                vis[v - 1] = true;
                q.push({v, lvl + 1});
            }
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> mat[i][j];
    }
    Solution obj;
    cout << obj.snakesAndLadders(mat);
}