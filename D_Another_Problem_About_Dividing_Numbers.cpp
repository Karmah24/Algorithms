#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    int a, b, k;
    cin >> a >> b >> k;
    if (a == b) {
        cout << "NO" << '\n';
        return;
    }
    if (k == 1) {
        if (a % b == 0 || b % a == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}