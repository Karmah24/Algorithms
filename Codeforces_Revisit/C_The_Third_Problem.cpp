#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll mul(ll x, ll y) {return ((x % MOD) * (y % MOD)) % MOD;}
//================================================================


int solve() {

    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    int l, r, res = 1;
    l = r = p[0];

    for (int i = 1; i < n; i++) {

        if (p[i] < l) l = p[i];
        else if (p[i] > r) r = p[i];
        else {
            res = mul(res, r - l + 1 - i);
        }
    }
    return res;
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
        cout << solve();
        cout << '\n';
    }
    return 0;
}