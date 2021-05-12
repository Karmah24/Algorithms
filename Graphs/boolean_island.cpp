#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define F first
#define S second
typedef pair<int, int>	pii;

const int N = 50, M = N;
//=========================

int mat[N][M];
bool vis[N][M] = { };
int n, m, region = 0, r_max = 0;

void dfs(pii s) {
    vis[s.F][s.S] = true;

    for (int i = s.F - 1; i <= s.F + 1 && i < n; i++) {
        if (i < 0) continue;
        for (int j = s.S - 1; j <= s.S + 1 && j < m; j++) {
            if (j < 0 || vis[i][j]) continue;
            if (mat[i][j] == 1) {
                region++;
                dfs({i, j});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    loop (i, n)
        loop (j, m)
            cin >> mat[i][j];
    
    loop (i, n)
        loop (j, m) 
            if (mat[i][j] == 1 && !vis[i][j]) {
                region++;
                dfs({i, j});
                r_max = max(r_max, region);
                region = 0;
            }
    cout << "#res " << r_max << endl;
    
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
        r_max = 0;
        for (auto & v : vis)
            for (auto & e : v)
                e = false;
    }
}