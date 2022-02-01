#include <bits/stdc++.h>
using namespace std;
#define int long long
//=======================

int solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e: a) cin >> e;
    int res = n - 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int curr = 0;
            for (int k = 0; k < n; k++) {
                if ((j - i) * (a[k] - a[i]) != (k - i) * (a[j] - a[i])) curr++;
            }
            res = min(res, curr);
        }
    }
    return res;
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