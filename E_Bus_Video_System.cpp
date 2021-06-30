#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    
    ll n, w;
    cin >> n >> w;
    ll bal = 0;
    ll l = 0, r = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        bal += x;
        l = min(l, bal);
        r = max(r, bal);
    }
    if (w - r < 0 || l + w < 0) cout << 0;
    else cout << w - r + l + 1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}