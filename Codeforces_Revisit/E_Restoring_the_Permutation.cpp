#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

class DSU {
public:
	int cnt;
	vector<int> par, rank;
	DSU(int n): par(n) {
		for (int i = 0; i < n; i++) par[i] = i;
	}
	int find(int x) {
		return par[x] == x ? x : par[x] = find(par[x]);
	}
	int merge(int x, int y) {
		if ((x = find(x)) == (y = find(y))) return y;
		par[x] = y;
		return y;
	}
};

void solve() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<bool> vis(n + 1, false);
	int k = 1;
	for (int i = 0; i < n; i++) {

		if (!vis[a[i]]) cout << a[i] << " ";
		else {
			while (k <= n && vis[k]) k++;
			cout << k << " ";
			vis[k] = true;
		}
		vis[a[i]] = true;
	}
	cout << '\n';
	DSU dsu(n + 1);
	for (int i = 0; i < n; i++) {
		
		a[i] = dsu.find(a[i]);
		cout << a[i] << " ";
		dsu.merge(a[i], a[i] - 1);
	}
}
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("../input.txt", "r", stdin);
	  freopen("../output.txt", "w", stdout);
	#endif
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
		cout << '\n';
	}
	return 0;
}