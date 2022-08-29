#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
bool solve() {

    int n;
    cin >> n;
    if (n == 1) return false;
    if (n % 2 == 1) return true;
    if ((n & (n - 1)) == 0 && n > 2) return false;
    if (n % 4 == 0) return true;
    return (n == 2 || !isPrime(n / 2));
    
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
        if (solve()) cout << "Ashishgup";
        else cout << "FastestFinger";
        cout << '\n';
    }
    return 0;
}
