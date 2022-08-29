#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {

    int n;
    vector<pair<int, int>> d(3);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i].first;
        d[i].second = i + 2;
    }
    sort(d.begin(), d.end());

    int i, k, p = 1;
    for (i = 5, k = 1; k < d[0].first; i++, k++) {
        cout << p << " " << i << '\n';
        p = i;
    }
    cout << p << " " << d[0].second << '\n';
    for (int i = 0; i < n; i++) 
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