#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int dp[105][105][2];

bool solve1(int n, int odd, int parity) {

    if (n == 1) return !(parity ^ odd);
    if (n == 0) return parity == 0;
    int &res = dp[n][odd][parity];
    if (res != -1) return res;

    int even = n - odd;
    vector<int> op(4, 1);
    if (odd >= 2) {

        op[0] = solve1(n - 2, odd - 2, 1 - parity);
    }
    if (odd >= 1 && even >= 1) {

        op[1] = solve1(n - 2, odd - 1, 1 - parity);
        op[2] = solve1(n - 2, odd - 1, parity);
    }
    if (even >= 2) {

        op[3] = solve1(n - 2, odd, parity);
    }
    return res = (op[0] && op[1] && odd >= 1) || (op[2] && op[3] && even >= 1);
}

bool solve2(int n, int i, int odd, int parity) {

    if (i == n) return parity == 0;
    int &res = dp[i][odd][parity];
    if (res != -1) return res;

    int even = n - i - odd;
    if (i % 2 == 0) { // Alice's turn

        res = 0;
        if (odd) res |= solve2(n, i + 1, odd - 1, 1 - parity);
        if (even) res |= solve2(n, i + 1, odd, parity);
    }
    else { // Bob's turn

        res = 1;
        if (odd) res &= solve2(n, i + 1, odd - 1, parity);
        if (even) res &= solve2(n, i + 1, odd, parity);
    }
    return res;
}

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0;
    for (int i = 0; i < n; i++) {

        cin >> a[i];
        odd += a[i] & 1;
    }
    memset(dp, -1, sizeof(dp));
    bool res = solve2(n, 0, odd, 0);
    if (res) cout << "Alice";
    else cout << "Bob";
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
