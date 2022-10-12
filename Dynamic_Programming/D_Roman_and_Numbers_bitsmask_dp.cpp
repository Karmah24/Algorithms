#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

string s;
int m, k, n;
int dp[1 << 19][105];
int fact[19];

int solve(int mask, int rem) {

    if (mask == 0) return rem == 0;
    int &res = dp[mask][rem];
    if (res != -1) return res;

    res = 0;
    for (int i = 0; i < n; i++) {

        if (!(mask & (1 << i))) continue;
        int x = s[i] - '0';
        if (mask == k && x == 0) continue;
        res += solve(mask ^ (1 << i), (rem * 10 + x) % m);
    }
    return res;
}

void testcase() {

    cin >> s >> m;
    n = s.size();
    k = (1 << n) - 1;
    // memset(dp, -1, sizeof(dp));
    // int res = solve(k, 0);

    dp[k][0] = 1;
    for (int mask = k; mask >= 0; mask--) {
        for (int rem = 0; rem < m; rem++) {

            for (int i = 0; i < n; i++) {

                if (!(mask & (1 << i))) continue;
                int x = s[i] - '0';
                if (mask == k && x == 0) continue;
                int nxt_rem = (rem * 10 + x) % m;
                int nxt_mask = mask ^ (1 << i);
                dp[nxt_mask][nxt_rem] += dp[mask][rem];
            }
        }
    }
    int res = dp[0][0];

    vector<int> cnt(10, 0);
    for (auto &d: s) cnt[d - '0']++;
    for (auto &e: cnt) res /= fact[e];
    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

    fact[0] = 1;
    for (int i = 1; i < 19; i++) fact[i] = fact[i - 1] * i;

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
