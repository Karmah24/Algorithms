#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

void testcase() {

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[a[i].second] = i;
    }
    vector<int> pfx(n);
    pfx[0] = a[0].first;
    for (int i = 1; i < n; i++) pfx[i] = pfx[i - 1] + a[i].first;
    int my_wins = upper_bound(pfx.begin(), pfx.end(), m) - pfx.begin();
    if (my_wins == 0) {
        cout << n + 1;
        return;
    }
    auto check = [&](int x) -> bool {
        if (my_wins > n - x) return 1;
        if (my_wins < n - x) return 0;
        if (my_wins == 1) return m >= a[pos[n - x]].first;
        return pfx[my_wins - 2] + a[pos[n - x]].first <= m;
    };
    int lo = 1, hi = n + 1, res;
    while (lo <= hi) {
    
        int mid = (lo + hi) / 2;
        if (check(mid)) {
    
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
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
