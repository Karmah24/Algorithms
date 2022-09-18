#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

	int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int res = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {

        if (b[j] < a[i] - k) j++;
        else if (b[j] > a[i] + k) i++;
        else {
            res++;
            i++, j++;
        }
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
