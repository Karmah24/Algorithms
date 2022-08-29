#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve(vector<int> &v) {

    sort(v.begin(), v.end());
    return v[v.size() / 2] - v[(v.size() - 1) / 2] + 1;
}
int solve() {

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    return solve(x) * solve(y);
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
        cout << solve();
        cout << '\n';
    }
    return 0;
}