#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

void testcase() {

    int m;
    cin >> m;

    auto check = [&](int x) -> int {

        int res = 0, k = 2;
        while (k * k * k <= x) {
            res += x / (k * k * k);
            k++;
        }
        return res;
    };
    int lo = 1, hi = INF, n = -1;
    while (lo <= hi) {
    
        int mid = (lo + hi) / 2;
        int x = check(mid);
        if (x >= m) {
    
            if (x == m) n = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << n;
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
