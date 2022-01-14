#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

void solve() {
    
    ll n, m;
    cin >> n >> m;

    ll kmax = ((n - m + 1) * (n - m)) / 2;

    ll x = n / m, y = n % m;

    ll kmin = (y * (((x + 1) * x) / 2)) + (m - y) * ((x * (x - 1)) / 2);

    cout << kmin << " " << kmax; 
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}