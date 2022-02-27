#include <bits/stdc++.h>
using namespace std;
//================================================================

bool solve(int n, int m, int k) {

    if (n % 2 == 0 && m % 2 == 0) return k % 2 == 0;
    if (n % 2 == 0 && m % 2 != 0) {
        int v = (n * m) / 2 - k;
        return v >= n/ 2 && solve(n, m - 1, k);
    }
    if (n % 2 != 0 && m % 2 == 0) {
        return k >= m / 2 && solve(n - 1, m, k - m / 2);
    }
    return false;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        if (solve(n, m, k)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}