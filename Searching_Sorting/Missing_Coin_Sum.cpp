// smallest sum not achievable by using a subset of given coins
 
#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

	int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int res = 0; // largest sum possible till now such that all lesser also possible

    for (int i = 0; i < n; i++) {

        // if res is max possible(all lesses also possbile) till now, with a[i] new min sum = a[i]
        // this will only increase with increasing i
        // if a[i] > res + 1 then sum of res + 1 will not be possbile
        // else new res = res + a[i]
        if (a[i] > res + 1) break;
        res += a[i];
    }
    cout << res + 1;
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
