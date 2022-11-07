#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

void testcase() {

    int n;
    cin >> n;
    int prod = 1, res = 0;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            prod *= i;
            prod %= n;
            res++;
        }
    }
    prod %= n;
    bool ok = 1;
    if (prod != 1) {
        ok = 0;
        res--;
    }
    cout << res << '\n';
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            if (ok || prod != i) cout << i << " ";
        }
    }
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
