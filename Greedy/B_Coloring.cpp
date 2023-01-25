#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

void testcase() {

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int mx_freq = (n + k - 1) / k;
    int cnt_mx_freq = n % k == 0 ? k : n % k;
    bool ok = 1;
    if (a.back() > mx_freq) ok = 0;
    if (count(a.begin(), a.end(), mx_freq) > cnt_mx_freq) ok = 0;
    cout << (ok ? "YES" : "NO");
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
