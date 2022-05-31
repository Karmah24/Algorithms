#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================
int k, q, n;
string s;
vector<vector<int>> ct;

pair<int, int> par(int i) {
    return {(i + 1) / 2 - 1, i % 2 == 0};
}
int set_cntr(int i) {
    auto [p, d] = par(i);
    int cntr = 0;
    if (s[i] == '?') cntr = ct[i][0] + ct[i][1];
    else cntr = ct[i][1 - s[i] + '0'];
    if (i > 0) ct[p][d] = cntr;
    return cntr;
}
int upd(int i) {
    while (i > 0) {
        auto [p, d] = par(i);
        set_cntr(i);
        i = p;
    }
    return set_cntr(0);
}
void solve() {
    cin >> k >> s >> q;
    n = (1 << k) - 1;

    reverse(s.begin(), s.end());
    ct.assign(n, vector<int>(2, 1));
    for (int i = n - 1; i > 0; i--) {
        set_cntr(i);
    }
    int res = set_cntr(0);
    while (q--) {
        int i;
        char ch;
        cin >> i >> ch;
        i = n - i;
        s[i] = ch;
        cout << upd(i) << '\n';
    }
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
        solve();
    }
    return 0;
}