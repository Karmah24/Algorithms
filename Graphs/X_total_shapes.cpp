#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define F first
#define S second
typedef pair<int, int>	pii;

const int N = 50, M = N;
//=========================

string mat[N];
bool vis[N][M] = { };
int n, m, regions = 0;

void dfs(pii s) {
    vis[s.F][s.S] = true;

    for (int i = s.F - 1; i <= s.F + 1 && i < n; i++) {
        if (i < 0 || vis[i][s.S]) continue;
        if (mat[i][s.S] == 'X')
            dfs(mp(i, s.S));
    }
    for (int j = s.S - 1; j <= s.S + 1 && j < m; j++) {
        if (j < 0 || vis[s.F][j]) continue;
        if (mat[s.F][j] == 'X')
            dfs(mp(s.F, j));
    }
}

void solve() {
    cin >> n >> m;
    loop (i, n)
            cin >> mat[i];
    
    loop (i, n)
        loop (j, m) 
            if (mat[i][j] == 'X' && !vis[i][j]) {
                regions++;
                dfs(mp(i, j));
            }
    cout << "#res " << regions << endl;
    
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
        regions = 0;
        for (auto & v : vis)
            for (auto & e : v)
                e = false;
    }
}