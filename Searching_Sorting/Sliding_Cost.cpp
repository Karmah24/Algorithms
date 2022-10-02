#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

multiset<int> lo, hi;
int lo_sum = 0, hi_sum = 0;

void rearrange() {

	if (hi.size() > lo.size()) {

        lo_sum += *hi.begin();
		lo.insert(*hi.begin());
        hi_sum -= *hi.begin();
		hi.erase(hi.begin());
	}
	else if (lo.size() > hi.size() + 1) {

        hi_sum += *lo.rbegin();
		hi.insert(*lo.rbegin());
        lo_sum -= *lo.rbegin();
		lo.erase(prev(lo.end()));
	}
}

void add_num(int x) {

	if (lo.empty() || x < *lo.rbegin()) {

        lo_sum += x;
        lo.insert(x);
    }
	else {

        hi_sum += x;
        hi.insert(x);
    }
	rearrange();
}

void del_num(int x) {

	if (x <= *lo.rbegin()) {

        lo_sum -= x;
        lo.erase(lo.find(x));
    }
	else {

        hi_sum -= x;
        hi.erase(hi.find(x));
    }
	rearrange();
}

long double get_median() {

	if (lo.size() > hi.size()) return *lo.rbegin();
	return (*lo.rbegin() + *hi.begin()) / 2.0;
}

void testcase() {

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> sliding_cost;
	int i = 0, j = 0;
	while (j < k) add_num(a[j++]);
	long double md = get_median();
    sliding_cost.push_back(abs(lo_sum - lo.size() * md) + abs(hi_sum - hi.size() * md));

	while (j < n) {

		del_num(a[i++]);
		add_num(a[j++]);
        long double md = get_median();
        sliding_cost.push_back(abs(lo_sum - lo.size() * md) + abs(hi_sum - hi.size() * md));
	}
    for (auto &e: sliding_cost) cout << e << " ";
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