#include <bits/stdc++.h>
using namespace std;
#define int long long
//=======================

int solve() {

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a == b) return 0;

    vector<int> ab(4, 0);
    for (int i = 0; i < n; i++) {
        ab[2 * (a[i] - '0') + b[i] - '0']++;
    }
    int res = ab[1] == ab[2] ? ab[1] + ab[2] : LLONG_MAX;
    // if (ab[2]) {
    //     res = min(res, ab[0] + 1 == ab[3] ? ab[3] * 2 + 1 : LLONG_MAX);
    // }
    if (ab[3]) {
        res = min(res, ab[0] == ab[3] - 1 ? ab[0] * 2 + 1: LLONG_MAX);
    }
    return res == LLONG_MAX ? -1 : res;
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

        cout << solve() << '\n';
    }
    return 0;
}