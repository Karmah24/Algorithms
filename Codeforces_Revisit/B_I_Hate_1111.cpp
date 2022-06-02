#include <bits/stdc++.h>
using namespace std;
//================================================================

int solve() {
    
    int n;
    cin >> n; 
    // n = 111 * a + 11 * b;    a < 11
    for (int a = 0; a < 11 && 111 * a <= n; a++) {
        if ((n - 111 * a) % 11 == 0) return true;
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
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}