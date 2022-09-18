#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 5;

#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) { return ((x % MOD) + (y % MOD)) % MOD; }
//================================================================

int n;
vector<vector<int>> owners, dp;

int solve(int i, int mask) {

    if (i == 100) return mask == (1 << n) - 1;
    int &res = dp[i][mask];
    if (res != -1) return res;

    res = solve(i + 1, mask);
    for (auto &e: owners[i]) {

        if (mask & (1 << e)) continue;
        res = add(res, solve(i + 1, mask | (1 << e)));
    }
    return res;
}

void testcase() {

    cin >> n;
    cin.ignore();
    owners.assign(100, vector<int>());
    string s;
    for (int i = 0; i < n; i++) {

        getline(cin, s);
        stringstream in(s);
        int x;
        while (in >> x) owners[x - 1].push_back(i);
    }
    dp.assign(100, vector<int>(1 << n, -1));
    cout << solve(0, 0);
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
