#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int n;
vector<int> a, b;

bool solve(int res) {

	vector<int> a1, b1;
	for (int i = 0; i < n; i++) {
		a1.push_back(a[i] & res);
		b1.push_back((b[i] & res) ^ res);
	}
	sort(a1.begin(), a1.end());
	sort(b1.begin(), b1.end());
	for (int i = 0; i < n; i++) {
		if (a1[i] != b1[i]) return false;
	}
	return true;
}
void testcase() {

    cin >> n;
	a.resize(n);
	b.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

	int res = 0;
    for (int i = 30; i >= 0; i--) {

		if (solve(res | (1 << i))) res |= (1 << i);
    }
	cout << res;
}
signed main() {
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