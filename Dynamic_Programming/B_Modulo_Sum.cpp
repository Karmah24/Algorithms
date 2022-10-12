#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int n, m;
vector<int> a;
int dp[1005][1005];

bool solve(int n, int s, bool f = 0) {

    if (n < 0) return s == 0 && f == 1;
    int &res = dp[n][s];
    if (res != -1) return res;

    return res = solve(n - 1, (s + a[n]) % m, 1) || solve(n - 1, s, f);
}

void testcase() {

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // if n > m
    // when we calculate modulo of prefix sums there will be atleast 2 same values.
    // S[i] % m = [0, m - 1] (m values)
    // and n > m
    // if S[l] % m == S[r] % m;  ∑a[i] % m (i -> [l + 1, r]) == 0
    // therefore, answer always exists.
    if (n > m) {
        cout << "YES";
        return;
    }
    memset(dp, -1, sizeof(dp));
    bool ok = solve(n - 1, 0);
    if (ok) cout << "YES";
    else cout << "NO";
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
