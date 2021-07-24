#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    int grid[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {-1, 0, -1}
    };
    ll dp[10][25];
    int dx[5] = {0, 0, 0, -1, 1};
    int dy[5] = {0, -1, 1, 0, 0};
    
    ll dfs(int r, int c, int k) {
        
        if (r == 4 || r < 0 || c == 3 || c < 0 || grid[r][c] == -1) return 0;
        if (k == 0) return 1;
        
        int u = grid[r][c];
        if (dp[u][k - 1] != -1) return dp[u][k - 1];
        
        dp[u][k - 1] = 0;
        for (int i = 0; i < 5; i++) {
            int r1 = r + dy[i], c1 = c + dx[i];
            
            dp[u][k - 1] += dfs(r1, c1, k - 1);
        }
        return dp[u][k - 1];
    }   
public:
	long long getCount(int N) {
	   
	   memset(dp, -1, sizeof(dp));
	   ll res = 0;
	   for (int i = 0; i < 3; i++) {
	       for (int j = 0; j < 3; j++) res += dfs(i, j, N - 1);
	   }
	   res += dfs(3, 1, N - 1);
	   return res;
	}
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    Solution obj;
    cout << obj.getCount(n);
}