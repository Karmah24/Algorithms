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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int xxor = 0;
    for (int i = 0; i < 31; i++) {
        int first_set = n, last_unset = -1;
        for (int j = 0; j < n; j++) {
            if ((a[j] >> i) & 1) {
                first_set = j;
                break;
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (!((b[j] >> i) & 1)) {
                last_unset = j;
                break;
            }
        }
        int cnt = 1;
        if (first_set == last_unset - 1) cnt = n - last_unset;
        if (last_unset == first_set - 1) cnt = n - first_set;
        if (cnt & 1) xxor |= (1 << i);
    }
    cout << xxor;
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
