#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto &[f, s]: a) cin >> s >> f;

    sort(a.begin(), a.end());
    multiset<int> st;

    int res = 0;
    for (int i = 0; i < n; i++) {

        auto itr = st.lower_bound(a[i].second + 1);
        if (itr == st.begin()) {

            if (st.size() < k) {

                res++;
                st.insert(a[i].first);
            }
        }
        else {

            res++;
            st.erase(--itr);
            st.insert(a[i].first);
        }
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
