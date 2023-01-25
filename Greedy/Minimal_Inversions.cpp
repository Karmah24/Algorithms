#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n), cnt_m(n + 2, 0), cnt_p(n + 2, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt_m[a[i]]++;
    }
    vector<int> changes(n, 0);
    for (int i = 0; i < n; i++) {
        int change = cnt_m[a[i] - 1] - cnt_p[a[i] + 1];
        int prv = i == 0 ? 0 : changes[i - 1];
        changes[i] = prv + change;
        cnt_m[a[i]]--, cnt_p[a[i]]++;
    }
    cout << *max_element(changes.begin(), changes.end());
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
