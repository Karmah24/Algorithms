#include <bits/stdc++.h>
using namespace std;
//================================================================

bool better(int x, int y, vector<vector<int>> &ranks) {
    int wins = 0;
    for (int i = 0; i < 5; i++) {
        if (ranks[x][i] < ranks[y][i]) wins++;
    }
    return wins >= 3;
}
int solve() {
    int n;
    cin >> n;
    vector<vector<int>> ranks(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) cin >> ranks[i][j];
    }
    int best = 0;
    for (int i = 1; i < n; i++) {
        if (better(i, best, ranks)) best = i;
    }
    for (int i = 0; i < n; i++) {
        if (i == best) continue;
        if (!better(best, i, ranks)) return -1;
    }
    return best + 1;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}