#include <bits/stdc++.h>
using namespace std;

class Solution {

    int x, y;
    
    void bfs(vector<vector<int>>& jumps, int i, int j, int n) {
        
        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        queue<pair<int, int>> q;
        q.push({i, j});
        jumps[i][j] = 0;
        
        if (i == x && j == y) return;
        
        while (!q.empty()) {
            
            pair<int, int> u = q.front();
            q.pop();
            
            for (int p = 0; p < 8; p++) {
                
                pair<int, int> v = {u.first + dx[p], u.second + dy[p]};
                
                if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= n) continue;
                if (jumps[v.first][v.second] != INT_MAX) continue;
                
                jumps[v.first][v.second] = jumps[u.first][u.second] + 1;
                if (v.first == x && v.second == y) return;
                q.push(v);
            }
        }
    }
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N) {
	    x = KnightPos[0] - 1, y = KnightPos[1] - 1;
	    vector<vector<int>> jumps(N, vector<int>(N, INT_MAX));
	    bfs(jumps, TargetPos[0] - 1, TargetPos[1] - 1, N);
	    return jumps[KnightPos[0] - 1][KnightPos[1] - 1];
	}
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vector<int> KnightPos(2), TargetPos(2);
    int N;
    cin >> N >> KnightPos[0] >> KnightPos[1] >> TargetPos[0] >> TargetPos[1];
    Solution obj;
    cout << obj.minStepToReachTarget(KnightPos, TargetPos, N);
}
