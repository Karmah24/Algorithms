#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve1() {
    
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }
    vector<int> lo(m), hi(m);
    lo[0] = pos[t[0] - 'a'].front();
    for (int i = 1; i < m; i++) {
        int c = t[i] - 'a';
        lo[i] = *upper_bound(pos[c].begin(), pos[c].end(), lo[i - 1]);
    }
    hi.back() = pos[t.back() - 'a'].back();
    for (int i = m - 2; i >= 0; i--) {
        int c = t[i] - 'a';
        hi[i] = *(lower_bound(pos[c].begin(), pos[c].end(), hi[i + 1]) - 1);
    }
    int res = 1;
    for (int i = 1; i < m; i++) {
        res = max(res, hi[i] - lo[i - 1]);
    }
    return res;
}

int solve() {

    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    vector<int> lo(m), hi(m);
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[k]) {
            lo[k++] = i;
        }
        if (k == m) break;
    }
    k = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == t[k]) {
            hi[k--] = i;
        }
        if (k == -1) break;
    }
    int res = 1;
    for (int i = 1; i < m; i++) {
        res = max(res, hi[i] - lo[i - 1]);
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
    // cin >> T;
    while (T--) {
        cout << solve();
        cout << '\n';
    }
    return 0;
}