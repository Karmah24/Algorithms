#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {

    int n;
    cin >> n;

    if (n % 2 == 1) {
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (j - i <= n / 2) cout << "1 ";
                else cout << "-1 ";
            }
        }
    }
    else {
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (j - i < n / 2) cout << "1 ";
                else if (j - i == n / 2) cout << "0 ";
                else cout << "-1 ";
            }
        }
    }
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
        solve();
        cout << '\n';
    }
    return 0;
}