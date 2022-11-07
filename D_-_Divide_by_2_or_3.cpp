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
    sort(a.begin(), a.end());

    int g = a[0];
    for (int i = 1; i < n; i++) g = gcd(g, a[i]);
    int res = 0, f = 1;
    for (int i = 0; i < n && f; i++) {

        while (a[i] != g && f) {

            if (a[i] % 3 == 0 && a[i] >= g * 3) {
                a[i] /= 3;
                res++;
            }
            else if (a[i] % 2 == 0 && a[i] >= g * 2) {
                a[i] /= 2;
                res++;
            }
            else f = 0;
        }
    }
    if (!f) res = -1;
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
