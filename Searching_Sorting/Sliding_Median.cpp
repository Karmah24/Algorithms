#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

multiset<int> lo, hi;

void rearrange() {

	if (hi.size() > lo.size()) {

		lo.insert(*hi.begin());
		hi.erase(hi.begin());
	}
	else if (lo.size() > hi.size() + 1) {

		hi.insert(*lo.rbegin());
		lo.erase(prev(lo.end()));
	}
}

void add_num(int x) {

	if (lo.empty() || x < *lo.rbegin()) lo.insert(x);
	else hi.insert(x);
	rearrange();
}

void del_num(int x) {

	if (x <= *lo.rbegin()) lo.erase(lo.find(x));
	else hi.erase(hi.find(x));
	rearrange();
}

double get_median() {

	return *lo.rbegin();
	// if (lo.size() > hi.size()) return *lo.rbegin();
	// return (*lo.rbegin() + *hi.begin()) / 2.0;
}

void testcase() {

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> sliding_median;
	int i = 0, j = 0;
	while (j < k) add_num(a[j++]);
	sliding_median.push_back(get_median());

	while (j < n) {

		del_num(a[i++]);
		add_num(a[j++]);
		sliding_median.push_back(get_median());
	}
	for (auto &e: sliding_median) cout << e << " ";
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