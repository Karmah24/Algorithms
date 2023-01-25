#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    cin >> m;
    map<int, int> x;
    for (int i = 0; i < m; i++) {
        int in;
        cin >> in;
        x[in]++;
    }
    bool ok = 1;
    for (int i = 0; i < n && ok; i++) if (a[i] < b[i]) ok = 0;
    stack<int> st;
    set<int> used;
    for (int i = 0; i < n && ok; i++) {
        while (!st.empty() && st.top() < b[i]) {
            if (used.count(st.top())) used.erase(used.find(st.top()));
            st.pop();
        }
        if (st.empty() || st.top() != b[i]) st.push(b[i]);
        if (a[i] == b[i] || used.count(b[i])) continue;
        if (--x[b[i]] < 0) ok = 0;
        used.insert(b[i]);
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
