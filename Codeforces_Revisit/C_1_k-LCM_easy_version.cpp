#include <bits/stdc++.h>
using namespace std;
//================================================================

void solve() {
    
    int n, k;
    cin >> n >> k;
    
    if (n % 2 == 1) cout << n / 2 << " " << n / 2 << " " << 1;
    else if (n % 4 != 0) cout << n / 2 - 1 << " " << n / 2 - 1 << " " << 2;
    else cout << n / 4 << " " << n / 4 << " " << n / 2;
    cout << '\n';
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
        solve();
    }
    return 0;
}