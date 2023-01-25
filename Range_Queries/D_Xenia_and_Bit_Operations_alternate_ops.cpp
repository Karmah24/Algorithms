#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = (1 << 17) + 5;
//================================================================

class SGT {
public:

    int n, st_op;
    vector<int> sgt;
    SGT(vector<int> &a, int st_op) {

        this->n = a.size();
        this->st_op = st_op;
        sgt.resize(4 * n);
        build(a);
    }
    int build(vector<int> &a, int op = -1, int sl = 0, int sr = -1, int idx = 0) {
        
        if (sr == -1) sr = n - 1;
        if (op == - 1) op = st_op;
        if (sl == sr) return sgt[idx] = a[sl];
        int mid = (sl + sr) / 2;
        int left = build(a, 1 - op, sl, mid, idx * 2 + 1);
        int right = build(a, 1 - op, mid + 1, sr, idx * 2 + 2);
        if (op == 1) sgt[idx] = left | right;
        else sgt[idx] = left ^ right;
        return sgt[idx];
    }
    int query(int ql, int qr, int op = -1, int sl = 0, int sr = -1, int idx = 0) {

        if (sr == -1) sr = n - 1;
        if (op == - 1) op = st_op;
        if (ql <= sl && sr <= qr) return sgt[idx];
        if (qr < sl || sr < ql) return 0;
        int mid = (sl + sr) / 2;
        int left = query(ql, qr, 1 - op, sl, mid, idx * 2 + 1);
        int right = query(ql, qr, 1 - op, mid + 1, sr, idx * 2 + 2);
        if (op == 1) return left | right;
        return left ^ right;
    }
    void update(int i, int k, int op = -1, int sl = 0, int sr = -1, int idx = 0) {

        if (sr == -1) sr = n - 1;
        if (op == - 1) op = st_op;
        if (sl == sr) {
            sgt[idx] = k;
            return;
        }
        int mid = (sl + sr) / 2;
        if (i <= mid) update(i, k, 1 - op, sl, mid, idx * 2 + 1);
        else update(i, k, 1 - op, mid + 1, sr, idx * 2 + 2);
        if (op == 1) sgt[idx] = sgt[idx * 2 + 1] | sgt[idx * 2 + 2];
        else sgt[idx] = sgt[idx * 2 + 1] ^ sgt[idx * 2 + 2];
    }
};

void testcase() {

    int n, q;
    cin >> n >> q;
    int sz = (1 << n);
    vector<int> a(sz);
    for (int i = 0; i < sz; i++) cin >> a[i];

    SGT sgt(a, n & 1);

    while (q--) {
        int i, k;
        cin >> i >> k;
        sgt.update(i - 1, k);
        cout << sgt.query(0, sz - 1) << '\n';
    }
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
