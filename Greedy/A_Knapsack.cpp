#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

void testcase() {

    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());
    pair<int, int> p = {w, n};
    a.erase(upper_bound(a.begin(), a.end(), p), a.end());
    if (a.empty()) {
        cout << -1;
        return;
    }
    if (a.back().first > (w + 1) / 2) {
        cout << "1\n" << a.back().second;
        return;
    }
    int s = 0, i = 0;
    while (i < a.size() && s < (w + 1) / 2) {
        s += a[i].first;
        i++;
    }
    if (s < (w + 1) / 2) {
        cout << -1;
        return;
    }
    cout << i << '\n';
    for (int j = 0; j < i; j++) {
        cout << a[j].second << " ";
    }
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
