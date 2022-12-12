#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

int n, c, d;
vector<int> a, pfx;

bool check(int x) {

    int cycles = d / (x + 1);
    int left = d % (x + 1);
    int res = cycles * pfx[min(n, x + 1)] + pfx[min(n, left)];
    return c <= res;
}

void testcase() {

    cin >> n >> c >> d;
    a.resize(n + 1);
    pfx.assign(n + 1, 0);
    for (int i = 1; i < n + 1; i++) cin >> a[i];
    a[0] = INF;
    sort(a.rbegin(), a.rend());
    a[0] = 0;
    for (int i = 1; i < n + 1; i++) pfx[i] = pfx[i - 1] + a[i];

    if (pfx[min(d, n)] >= c) {
        cout << "Infinity";
        return;
    }
    if (a[1] * d < c) {
        cout << "Impossible";
        return;
    }

    int lo = 0, hi = INF, res = 0;
    while (lo <= hi) {
    
        int mid = (lo + hi) / 2;
        if (check(mid)) {
    
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
