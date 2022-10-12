#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

vector<int> a;

void solve(int l, int r, int sum, vector<int> &st) {

    if (l > r) {

        st.push_back(sum);
        return;
    }
    solve(l + 1, r, sum + a[l], st);
    solve(l + 1, r, sum, st);
}

void testcase() {

    int n, t;
    cin >> n >> t;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> s1, s2;
    solve(0, (n - 1) / 2, 0, s1);
    solve((n - 1) / 2 + 1, n - 1, 0, s2);

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    int res = 0;
    for (auto &e: s1) {

        res += upper_bound(s2.begin(), s2.end(), t - e) - lower_bound(s2.begin(), s2.end(), t - e);
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
