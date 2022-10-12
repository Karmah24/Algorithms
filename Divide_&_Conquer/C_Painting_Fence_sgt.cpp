#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = (1 << 20) - 1; // n upto 2e5
//================================================================

int n;
vector<int> a;
int sgt[N]; // N >= 4n

auto cmp = [](int x, int y) {
    return a[x] <= a[y];
};

int build_sgt(int idx, int l, int r) {

    if (l == r) return sgt[idx] = l;
    int mid = (l + r) / 2;
    int left = build_sgt(2 * idx + 1, l, mid);
    int right = build_sgt(2 * idx + 2, mid + 1, r);
    return sgt[idx] = min(left, right, cmp);
}

// sl, sr : sgt bounds; ql, qr : query bounds
int query(int idx, int sl, int sr, int ql, int qr) {

    if (sr < ql || qr < sl) return n;
    if (ql <= sl && sr <= qr) return sgt[idx];
    int mid = (sl + sr) / 2;
    int left = query(2 * idx + 1, sl, mid, ql, qr);
    int right = query(2 * idx + 2, mid + 1, sr, ql, qr);
    return min(left, right, cmp);
}

int solve(int l, int r, int h) {

    if (l > r) return 0;
    int m = query(0, 0, n - 1, l, r);
    int mn = a[m];
    return min(r - l + 1, solve(l, m - 1, mn) + solve(m + 1, r, mn) + mn - h);
}

void testcase() {

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    a.push_back(INF);
    build_sgt(0, 0, n - 1);
    cout << solve(0, n - 1, 0);
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
