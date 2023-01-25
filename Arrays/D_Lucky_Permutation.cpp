#include <bits/stdc++.h>
using namespace std;
//================================================================

class DSU {
public:
	int cnt;
	vector<int> par, rank;
	DSU(int n) : par(n), rank(n, 0), cnt(n) {
		for (int i = 0; i < n; i++) par[i] = i;
	}
	int find(int x) {
		return par[x] == x ? x : par[x] = find(par[x]);
	}
	int merge(int x, int y) {
		if ((x = find(x)) == (y = find(y))) return y;
		cnt--;
		if (rank[x] > rank[y]) swap(x, y);
		par[x] = y;
		if (rank[x] == rank[y]) rank[y]++;
		return y;
	}
};

int count_swaps(vector<int> &a, DSU &dsu) {
	int n = a.size();
	vector<bool> vis(n, 0);
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		int j = i;
		c++;
		while (!vis[j]) {
			vis[j] = 1; 
			dsu.merge(j, a[j] - 1);
			j = a[j] - 1;
		}
	}
	return n - c;
}

void testcase() {

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int res = n;
	DSU dsu(n);
	int swaps_to_sort = count_swaps(a, dsu);
	for (int i = 0; i < n - 1; i++) {
		int diff = dsu.find(i) == dsu.find(i + 1) ? -1 : 1;
		res = min(res, swaps_to_sort + diff);
	}
	cout << res;
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
