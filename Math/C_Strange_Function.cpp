#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) { return ((x % MOD) + (y % MOD)) % MOD; }
//================================================================

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void testcase() {

    int n;
    cin >> n;
    int i = 2, x = 2, res = 0, curr = n;
    while (curr) {

        res = add(res, (curr - n / x) * i);
        curr = n / x;
        x = lcm(x, i + 1);
        i++;
    }
    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
