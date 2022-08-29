#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {

    string s;
    cin >> s;
    vector<int> sfx(2, 0), pfx(2, 0);
    for (auto &ch: s) {
        sfx[ch - '0']++;
    }
    int res = min(sfx[0], sfx[1]);
    for (auto &ch: s) {
        pfx[ch - '0']++, sfx[ch - '0']--;
        res = min(res, pfx[0] + sfx[1]); // 111...000
        res = min(res, pfx[1] + sfx[0]); // 000...111
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