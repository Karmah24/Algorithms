#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int g = a[0];
    for (int i = 1; i < n; i++) g = gcd(g, a[i]);
    for (int i = 0; i < n; i++) a[i] /= g;
    int res = 0, ok = 1;
    for (int i = 0; i < n && ok; i++) {

        while (a[i] != 1 && ok) {

            if (a[i] % 3 == 0) {
                a[i] /= 3;
                res++;
            }
            else if (a[i] % 2 == 0) {
                a[i] /= 2;
                res++;
            }
            else ok = 0;
        }
    }
    if (!ok) res = -1;
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
