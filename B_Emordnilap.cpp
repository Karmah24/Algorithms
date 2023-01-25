#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

int fact[N];

void testcase() {

    int n;
    cin >> n;

    int res = fact[n] * (n - 1);
    res %= MOD;
    res *= n;
    res %= MOD;
    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }
	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
