#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mn = INT_MAX, k = -1;
    for (int i = 0; i < n - 1; i++) {
        if (mn > a[i + 1] - a[i]) {
            mn = a[i + 1] - a[i];
            k = i;
        }
    }
    cout << a[k] << " ";
    for (int j = k + 2; j < n; j++) cout << a[j] << " ";
    for (int j = 0; j < k; j++) cout << a[j] << " ";
    cout << a[k + 1] << " ";
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