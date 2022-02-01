#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}
ll mul(ll x, ll y) {return ((x % MOD) * (y % MOD)) % MOD;}
ll mpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}
//=======================

int solve() {
    
    int n, m, x, k, res = 0;
    cin >> n >> m;
    int all_or = 0;
    while (m--) {
        cin >> x >> x >> x;
        all_or |= x;
    }
    x = 1, k = mpow(2, n - 1);
    // for (int i = 0; i < 31; i++) {
    //     if (all_or & x) {
    //         res = add(res, mul(x, k));
    //     }
    //     x = x << 1;
    // }
    res = mul(all_or, k);
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