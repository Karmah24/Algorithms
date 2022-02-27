#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================
int h, c, t;

int diff(int x) {
    return ((x + 1) * h + x * c) - (t * (2 * x + 1));
}
int solve() {
    cin >> h >> c >> t;

    if (t <= (h + c) / 2) return 2;

    int lo = 1, hi = 1e10, res = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (diff(mid) > 0) lo = mid + 1;
        else hi = mid - 1;

        if (abs(diff(mid)) * (2 * res + 1) < abs(diff(res)) * (2 * mid + 1)) {
            res = mid;
        }
        else if (abs(diff(mid)) * (2 * res + 1) == abs(diff(res) * (2 * mid + 1))
            && mid < res) {
            res = mid;
        }
    }
    return 2 * res + 1;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("..input.txt", "r", stdin);
        freopen("..output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}