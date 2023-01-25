#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

void testcase() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> a[i];

    int cnt = 0;
    vector<int> v(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        v[a[i]] = 1;
        v[a[i]] += v[a[i] - 1];
    }
    int res = INF;
    for (int r = 1; r < n + 1; r++) {
        int l = r - v[r];
        res = min(res, ((l + k - 1) / k) + ((n - r + k - 1) / k));
    }
    cout << res;
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
