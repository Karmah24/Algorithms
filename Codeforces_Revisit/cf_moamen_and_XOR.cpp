#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}
ll sub(ll x, ll y) {return ((x % MOD) - (y % MOD) + MOD) % MOD;}
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
//================================================================

int solve() {
    int n, k;
    cin >> n >> k;
    if (k == 0) return 1;
    int res = 0;
    if (n % 2 != 0) {
        res = add(mpow(2, sub(n, 1)), 1);
        res = mpow(res, k);
        return res;
    }
    int x = sub(mpow(2, sub(n, 1)), 1), y = mpow(2, n);
    for (int i = 1; i <= k; i++) {
        int curr = mpow(x, sub(k, i));
        curr = mul(curr, mpow(y, sub(i, 1)));
        res = add(res, curr);
    }
    res = add(res, mpow(x, k));
    return res;
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
        cout << solve() << '\n';
    }
    return 0;
}