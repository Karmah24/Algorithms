#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {

        cin >> a[i];
        cnt[a[i]]++;
    }
    int x = 0;
    for (auto itr = cnt.rbegin(); itr != cnt.rend(); itr++) {

        if (itr->first <= n) break;
        x += itr->second;
    } 
    vector<int> sfx(n + 1, 0);
    sfx[n] = x;
    for (int i = n - 1; i >= 1; i--) {
        
        sfx[i] = sfx[i + 1] + cnt[i + 1];
    }
    vector<int> pfx(n + 2, 0), missing(n + 2, 0);
    for (int i = 1; i < n + 2; i++) {

        pfx[i] = pfx[i - 1] + max(0LL, cnt[i - 1] - 1);
        missing[i] = missing[i - 1] + (cnt[i - 1] == 0);
    }
    auto check = [&](int mid) -> bool {

        return (sfx[mid] + pfx[mid + 1]) / 2 >= missing[mid + 1];
    };
    int lo = 0, hi = n, res;
    while (lo <= hi) {
    
        int mid = (lo + hi) / 2;
        if (check(mid)) {
    
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
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
