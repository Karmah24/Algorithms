#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {

    int x = 1112;
    for (int i = 0; i <= x / 11; i++) {

        int y = x - i * 11;
        int j = y / 111;
        if (y % 111 == 0) {
            cout << "i: " << i << " " << '\n';
            cout << "j: " << j << " " << '\n';
        }
    }
    return 0;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}