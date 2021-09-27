// #include <bits/stdc++.h>
#include <numeric>
#include <iostream>
using namespace std;

#define ln '\n'
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
//=======================

int solve() {
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        // cout << solve() << ln;
        cout << gcd(12, 56) * 5;
    }
    return 0;
}