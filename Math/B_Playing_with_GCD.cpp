#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++) cin >> a[i];

    b.push_back(a[0]);
    b.push_back(a[0]);
    for (int i = 1; i < n; i++) {

        b[i] = lcm(b[i], a[i]);
        b.push_back(a[i]);
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) {
        if (gcd(b[i], b[i + 1]) != a[i]) ok = 0;
    }
    if (ok) cout << "YES";
    else cout << "NO";
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
