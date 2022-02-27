#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(n);
    for (int i = 0; i < 20; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += (a[j] >> i) & 1;
        }
        for (int k = 0; k < cnt; k++) {
            b[k] |= 1 << i;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += b[i] * b[i];
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}