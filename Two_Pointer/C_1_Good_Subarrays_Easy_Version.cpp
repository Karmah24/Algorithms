#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0, idx = 1, r = 0;
    while (r < n) {

        if (a[r] >= idx) {
            res += idx;
            idx++;
            r++;
        }
        else idx--;
    }
    cout << res;
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
