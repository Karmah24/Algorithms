#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
ll mul(ll x, ll y) {return ((x % MOD) * (y % MOD)) % MOD;}
ll mpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = mul(res, x);
        }
        x = mul(x, x);
        n = n >> 1;
    }
    return res;
}

void solve() {

    ll n, m;
    cin >> n >> m;
    cout << mpow(mpow(2, n) - 1, m) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}