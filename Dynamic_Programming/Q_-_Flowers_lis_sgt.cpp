#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

class SGT {
public:

    int n;
    vector<int> sgt;
    SGT(int n) {
        this->n = n;
        sgt.assign(4 * n, 0);
    }
    void update(int k, int i, int sl = 0, int sr = -1, int idx = 0) {
        
        if (sr == -1) sr = n - 1;
        if (sl == sr) {
            sgt[idx] = k;
            return;
        }
        int mid = (sl + sr) / 2;
        if (i <= mid) update(k, i, sl, mid, idx * 2 + 1);
        else update(k, i, mid + 1, sr, idx * 2 + 2);
        sgt[idx] = max(sgt[idx * 2 + 1], sgt[idx * 2 + 2]);
    }
    int query(int ql, int qr, int sl = 0, int sr = -1, int idx = 0) {

        if (sr == -1) sr = n - 1;
        if (ql <= sl && sr <= qr) return sgt[idx];
        if (qr < sl || sr < ql) return 0;
        int mid = (sl + sr) / 2;
        int left = query(ql, qr, sl, mid, idx * 2 + 1);
        int right = query(ql, qr, mid + 1, sr, idx * 2 + 2);
        return max(left, right);
    }
};

void testcase() {

    int n;
    cin >> n;
    vector<int> a(n), h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    // dp[i] = max(dp[j] + a[i]) : j < i, h[j] < h[i]
    vector<int> dp(n);
    SGT sgt(n + 1);
    for (int i = 0; i < n; i++) {

        dp[i] = sgt.query(1, h[i] - 1) + a[i];
        sgt.update(dp[i], h[i]);
    }
    cout << *max_element(dp.begin(), dp.end());
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
