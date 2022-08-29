#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {
    
    int n;
    cin >> n;
    vector<priority_queue<int>> diff(5);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<int> cnt(5, 0);
        for (auto &ch: s) cnt[ch - 'a']++;
        for (int i = 0; i < 5; i++) diff[i].push(2 * cnt[i] - s.size());
    }
    int res = 0;
    for (int i = 0; i < 5; i++) {
        if (diff[i].top() <= 0) continue;
        int curr = 0, excess = 0;
        while ((excess + diff[i].top()) > 0 && !diff[i].empty()) {
            excess += diff[i].top(); diff[i].pop();
            curr++;
        }
        res = max(res, curr);
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve();
        cout << '\n';
    }
    return 0;
}