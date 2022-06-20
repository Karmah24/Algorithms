#include <bits/stdc++.h>
using namespace std;
//================================================================

int solve() {
    
    int n, s;
    cin >> n >> s;
    vector<int> a(n), pfxSum(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];

    pfxSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        pfxSum[i] = pfxSum[i - 1] + a[i - 1];
    }
    int res = n + 1;
    for (int l = 1; l <= n; l++) {

        int lo = l, hi = n, curr = n + 1;
        while (lo <= hi) {
            int r = (lo + hi) / 2;
            int subSum = pfxSum[r] - pfxSum[l - 1];
            if (subSum <= s) {
                if (subSum == s) curr = n - 1 - r + l;
                lo = r + 1;
            }
            else hi = r - 1;
        }
        res = min(res, curr);
    }
    return res == n + 1 ? -1 : res;
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
        cout << solve() << '\n';
    }
    return 0;
}