#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 2e5 + 5;
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
//================================================================

int dp[N];
int invmod;

int solve(int n, int p) {

    if (n <= 0) return 0;
    int &res = dp[n];
    if (res != -1) return res;

    res = 0;
    res = mul(invmod, mul(p, solve(n - 2, p)));
    res = add(res, mul(invmod, mul(100 - p, solve(n - 1, p))));
    res = add(res, 1);
    return res;
}

void testcase() {

    int n, p;
    cin >> n >> p;
    memset(dp, -1, sizeof(dp));
    cout << solve(n, p);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
    invmod = inv(100);
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
