#include <bits/stdc++.h>
using namespace std;
//================================================================

int solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<pair<int, int>>> p(m, vector<pair<int, int>>(n));
    vector<int> mx(n, -1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j].first;
            p[i][j].second = j;
            mx[j] = max(mx[j], p[i][j].first);
        }
        sort(p[i].rbegin(), p[i].rend());
    }
    sort(p.rbegin(), p.rend(), [&](auto &v1, auto &v2){
        return v1[1].first < v2[1].first;
    });
    int res = p[0][1].first;
    for (int i = 0; i < n; i++) {
        if (i == p[0][0].second || i == p[0][1].second) continue;
        res = min(res, mx[i]);
    }
    return res;
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