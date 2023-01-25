#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

void testcase() {

    int n, x;
    cin >> n;
    vector<int> a(N, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    vector<int> d(N, 0);
    // d[i] = count of numbers in the given sequence divisible by i.
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            d[i] += a[j];
        }
    }
    vector<int> dp(N, 0);
    for (int i = N - 1; i >= 1; i--) {
        dp[i] = (d[i] * (d[i] - 1) * (d[i] - 2)) / 6;
        for (int j = 2 * i; j < N; j += i) dp[i] -= dp[j];
    }
    cout << dp[1];
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
