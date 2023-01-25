#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto can_cross = [&](vector<int> &temp) -> bool {
        int reach = 0;
        for (int i = 0; i < n; i++) {
            if (i > reach) return 0;
            int jump_sz = a[i] * (1 - temp[i]);
            reach = max(reach, i + jump_sz);
        }
        return 1;
    };
    vector<int> v(n, 0);
    if (!can_cross(v)) {
        cout << -1;
        return;
    }
    auto check = [&](int k) -> bool {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) temp[i] = v[i] | ((a[i] >> k) & 1);
        if (temp[0] || temp[n - 1] || !can_cross(temp)) return 0;
        v = temp;
        return 1;
    };
    int res = 0;
    for (int i = 30; i >= 0; i--) {
        if (!check(i)) res |= (1 << i);
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
