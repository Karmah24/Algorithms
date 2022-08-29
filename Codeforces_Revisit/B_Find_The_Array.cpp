#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> s(2, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i % 2] += a[i];
    }
    if (s[0] < s[1]) {
        for (int i = 1; i < n; i += 2) {
            cout << "1 " << a[i] << " ";
        }
        if (n % 2 == 1) cout << 1;
    }
    else {
        for (int i = 0; i < n - 1; i += 2) {
            cout << a[i] << " " << "1 ";
        }
        if (n % 2 == 1) cout << a[n - 1];
    }
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
        solve();
        cout << '\n';
    }
    return 0;
}