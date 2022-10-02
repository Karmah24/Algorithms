#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
//================================================================

void testcase() {

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end(), [](auto a, auto b){
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    vector<int> contains(n, 0), contained(n, 0);
    indexed_set<pair<int, int>> prev;
    prev.insert({a[n - 1][1], -n});
    for (int i = n - 2; i >= 0; i--) {

        contains[a[i][2]] = prev.order_of_key({a[i][1], -i - 1});
        prev.insert({a[i][1], -i - 1});
    }
    prev.clear();
    prev.insert({a[0][1], -1});
    for (int i = 1; i < n; i++) {

        contained[a[i][2]] = prev.size() - prev.order_of_key({a[i][1], -i - 1});
        prev.insert({a[i][1], -i - 1});
    }
    for (auto &e: contains) cout << e << " ";
    cout << '\n';
    for (auto &e: contained) cout << e << " ";
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
