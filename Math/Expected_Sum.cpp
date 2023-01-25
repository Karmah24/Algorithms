#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
#define ll long long
const ll MOD = 998244353;
ll add(ll x, ll y) { return ((x % MOD) + (y % MOD)) % MOD; }
ll mul(ll x, ll y) { return ((x % MOD) * (y % MOD)) % MOD; }
ll mpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}
ll inv(ll i) { return mpow(i, MOD - 2); }
ll sub(ll x, ll y) { return ((x % MOD) - (y % MOD) + MOD) % MOD; }
//================================================================

void testcase() {

    int a, b;
    cin >> a >> b;
    int n = a + b;
    int k = (n + 1) / 2;
    cout << mul(mul(a, k), inv(n));
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
