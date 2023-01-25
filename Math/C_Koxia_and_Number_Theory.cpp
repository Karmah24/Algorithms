#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bool ok = 1;
    for (int i = 0; i < n && ok; i++) {
        for (int j = i + 1; j < n; j++) if (a[i] == a[j]) ok = 0;
    }
    for (int p = 2; p < n + 1 && ok; p++) {
        vector<int> rem(p, 0);
        for (int i = 0; i < n; i++) {
            rem[a[i] % p]++;
        }
        if (*min_element(rem.begin(), rem.end()) >= 2) ok = 0;
    }
    cout << (ok ? "YES" : "NO");
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
