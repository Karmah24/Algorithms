#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

int lis(vector<pair<int, int>> &xy) {

    sort(xy.begin(), xy.end());
    vector<int> y;
    for (int i = 0; i < xy.size(); i++) y.push_back(-xy[i].second);
    vector<int> lis_path;
    for (auto &e: y)  {
        auto lb = lower_bound(lis_path.begin(), lis_path.end(), e);
        if (lb == lis_path.end()) lis_path.push_back(e);
        else *lb = e;
    }
    return lis_path.size();
}
void testcase() {

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> special;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        if (x == n || y == m) continue;
        special.push_back({x, -y});
    }
    cout << n + m - 2 - lis(special);
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
