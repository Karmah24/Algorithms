#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

bool solve() {

    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];

    int x = 1;
    for (int i = 0; i < 32; i++) {

        int on = 0;
        for (int i = 0; i < 3; i++) {
            on += a[i] & x;
        }
        if (on == 3 || on == 0) {
            return a[0] == a[1] && a[1] == a[2];
        }
        for (int i = 0; i < 3; i++) {
            
            if (a[i] & x == 2 - on) a[i] += x;
        }
        for (int i = 0; i < 3; i++) {
            a[i] = a[i] >> 1;
        }
        x == x << 1;
    }
    return 0;
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
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}