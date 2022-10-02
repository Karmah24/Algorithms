#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void testcase() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    auto check = [&](int x) -> bool {

        int y = 1, s = 0;
        for (int i = 0; i < n; i++) {

            if (s + a[i] > x) {
                
                y++;
                s = a[i];
            }
            else s += a[i];
        }
        return y <= k;
    };

    int lo = mx, hi = 1e15, res;
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
