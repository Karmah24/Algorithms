#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

bool solve() {

    int n;
    cin >> n;
    vector<int> a(n), l(n, 0), r(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (a[0] < 0 || a[n - 1] > 0) return 0;

    r[0] = l[1] = a[0];

    for (int i = 1; i < n - 1; i++) {

        r[i] = a[i] + l[i];
        if (r[i] < 0) return 0;
        if (r[i - 1] == 0 && a[i] != 0) return 0;
        l[i + 1] = l[i] + r[i] - r[i - 1];
        if (l[i + 1] < 0) return 0;
    }
    return r[n - 2] == l[n - 1] && l[n - 1] == -a[n - 1];
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