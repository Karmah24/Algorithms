// given arr[n] collect all number in increasing order going left to right
// return minimum number of rounds required

#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n), idx(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    int res = 1;
    for (int i = 1; i < n; i++) {

        if (idx[i + 1] < idx[i]) res++; // new round required
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
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
