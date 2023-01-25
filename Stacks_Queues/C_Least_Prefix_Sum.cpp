#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

void testcase() {

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> a[i];

    int res = 0, s = 0;
    priority_queue<int> pq;
    for (int i = m; i >= 2; i--) {
        s += a[i];
        pq.push(a[i]);
        if (s > 0) {
            res++;
            int tp = pq.top(); pq.pop();
            s -= 2 * tp;
            pq.push(-tp);
        }
    }
    while (!pq.empty()) pq.pop();
    s = 0;
    for (int i = m + 1; i < n + 1; i++) {
        s += a[i];
        pq.push(-a[i]);
        if (s < 0) {
            res++;
            int tp = pq.top(); pq.pop();
            s -= 2 * -tp;
            pq.push(-tp);
        }
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
