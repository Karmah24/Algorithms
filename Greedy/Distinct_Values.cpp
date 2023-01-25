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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> nxt(n, -1), prv(n, -1); // greater or equal
	stack<int> st;
	for (int i = 0; i < n; i++) {
		while (st.size() && st.top() < a[i]) st.pop();
		if (st.size()) prv[i] = st.top();
		st.push(a[i]);
	}
	while (st.size()) st.pop();
	for (int i = n - 1; i >= 0; i--)  {
		while (st.size() && st.top() < a[i]) st.pop();
		if (st.size()) nxt[i] = st.top();
		st.push(a[i]);
	}
	set<int> possible_vals;
	for (int i = 0; i < n; i++) {
		if (prv[i] != -1) possible_vals.insert(prv[i] - a[i]);
		if (nxt[i] != -1) possible_vals.insert(nxt[i] - a[i]);
	}
	cout << possible_vals.size();
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
