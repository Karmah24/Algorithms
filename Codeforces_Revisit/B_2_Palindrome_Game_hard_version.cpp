#include <bits/stdc++.h>
using namespace std;
//================================================================

int solve() {

    int n;
    string s;
    cin >> n >> s;
    int zeros = 0;
    bool isPd = true;

    for (int i = 0; i < n / 2; i++) if (s[i] != s[n - 1 - i]) isPd = false;
    for (auto &ch: s) if (ch == '0') zeros++;

    if (!isPd) {
        if (n % 2 == 1 && zeros == 2 && s[n / 2] == '0') return 0;
        else return 1;
    }
    if (zeros % 2 == 1 && zeros != 1) return 1;
    return 2;
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
        int res = solve();
        if (res == 0) cout << "DRAW\n";
        else if (res == 1) cout << "ALICE\n";
        else cout << "BOB\n";
    }
    return 0;
}