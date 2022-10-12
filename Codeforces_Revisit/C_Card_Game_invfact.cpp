#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ll long long
// const ll MOD = 1e9 + 7;
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
//================================================================

int fact[62], invfact[62];

int nCr(int n, int r) {

    int res = fact[n];
    res = mul(res, invfact[r]);
    res = mul(res, invfact[n - r]);
    return res;
}

void solve(int n, int p, vector<int> &res) {

    if (n < 2) return;
    // p winning on this turn, p gets the largest remaining card (n), rest can be distrubuted in any way.
    res[p] = add(res[p], nCr(n - 1, n / 2 - 1));
    if (n < 4) return;
    // 1 - p winning on this turn, 1 - p gets n and n - 1, rest can be distributed in any way.
    res[1 - p] = add(res[1 - p], nCr(n - 2, n / 2 - 2));
    // game continues.
    solve(n - 2, 1 - p, res);
}

void testcase() {

    int n;
    cin >> n;

    vector<int> res(2, 0);
    solve(n, 0, res);
    cout << res[0] << " " << res[1] << " " << 1;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

    fact[0] = 1;
    for (int i = 1; i < 62; i++) fact[i] = mul(fact[i - 1], i);
    for (int i = 0; i < 62; i++) invfact[i] = inv(fact[i]);

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
