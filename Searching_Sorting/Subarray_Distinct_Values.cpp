#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int i = 0, j = 0;
    map<int, int> mp;
    int res = 0;
    while (j < n) {

        if (mp.size() > k || (mp.size() == k && mp.count(a[j]) == 0)) {

            if (--mp[a[i]] == 0) mp.erase(a[i]);
            i++;
        }
        else {

            res += j - i + 1;
            mp[a[j]]++;
            j++;
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
