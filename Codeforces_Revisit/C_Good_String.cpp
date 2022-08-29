#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {

    string s;
    cin >> s;

    int res = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            int f = i, sz = 0;
            for (int k = 0; k < s.size(); k++) {
                if (s[k] - '0' == f) {
                    sz++;
                    f = i + j - f;
                }
            }
            if (sz % 2 == 1 && i != j) sz--;
            res = max(res, sz);
        }
    }
    return s.size() - res;
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