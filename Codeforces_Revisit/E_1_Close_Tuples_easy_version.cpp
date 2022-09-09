#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 5;
//================================================================

void testcase() {

	int n;
    cin >> n;
    vector<int> a(n), cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int res = 0;
    // x, x + 1, x + 2
    // x, x + 1, x + 1
    // x, x + 2, x + 2
    // x, x, x + 1
    // x, x, x + 2
    // x, x, x
    for (int i = 1; i < n - 1; i++) {
        res += cnt[i] * cnt[i + 1] * cnt[i + 2];
    }
    for (int i = 1; i < n; i++) {
        res += cnt[i] * (cnt[i + 1] * (cnt[i + 1] - 1)) / 2;
    }
    for (int i = 1; i < n - 1; i++) {
        res += cnt[i] * (cnt[i + 2] * (cnt[i + 2] - 1)) / 2;
    }
    for (int i = 1; i < n; i++) {
        res += cnt[i + 1] * (cnt[i] * (cnt[i] - 1)) / 2;
    }
    for (int i = 1; i < n - 1; i++) {
        res += cnt[i + 2] * (cnt[i] * (cnt[i] - 1)) / 2;
    }
    for (int i = 1; i <= n; i++) {
        res += (cnt[i] * (cnt[i] - 1) * (cnt[i] - 2)) / 6;
    }
    cout << res;
}
signed main() {
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