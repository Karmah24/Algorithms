#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {
    
    string s;
    cin >> s;
    int res = 0, c1 = 0, c2 = 0, f = 0;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] - '0' == f || s[i] == '?') c1++;
        else c1 = 0;
        if (s[i] - '0' == 1 - f || s[i] == '?') c2++;
        else c2 = 0;
        res += max(c1, c2);
        f = 1 - f;
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve();
        cout << '\n';
    }
    return 0;
}