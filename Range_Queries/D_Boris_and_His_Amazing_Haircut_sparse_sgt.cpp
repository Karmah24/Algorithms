#include <bits/stdc++.h>
using namespace std;
//================================================================

class SGT {
public:

    int n;
    vector<int> sgt;
    SGT(int n) {
        this->n = n;
        sgt.assign(4 * n, -1);
    }
    void update(int i, int k, int sl = 0, int sr = -1, int idx = 0) {
        if (sr == -1) sr = n - 1;
        if (sl == sr) {
            sgt[idx] = k;
            return;
        }
        int mid = (sl + sr) / 2;
        if (i <= mid) update(i, k, sl, mid, idx * 2 + 1);
        else update(i, k, mid + 1, sr, idx * 2 + 2);
        sgt[idx] = max(sgt[idx * 2 + 1], sgt[idx * 2 + 2]);
    }
    int query(int ql, int qr, int sl = 0, int sr = -1, int idx = 0) {
        if (sr == -1) sr = n - 1;
        if (ql <= sl && sr <= qr) return sgt[idx];
        if (qr < sl || sr < ql) return -1;
        int mid = (sl + sr) / 2;
        int left = query(ql, qr, sl, mid, idx * 2 + 1);
        int right = query(ql, qr, mid + 1, sr, idx * 2 + 2);
        return max(left, right);
    }
};

void compress(vector<reference_wrapper<vector<int>>> &arrs) {

    map<int, int> compressed;
    vector<int> concat;
    for (auto &a: arrs) {
        concat.insert(concat.end(), a.get().begin(), a.get().end());
    }
    sort(concat.begin(), concat.end());
    concat.erase(unique(concat.begin(), concat.end()), concat.end());
    for (int i = 0; i < concat.size(); i++) compressed[concat[i]] = i;
    for (auto &a: arrs) {
        for (auto &e: a.get()) e = compressed[e];
    }
}

void testcase() {

    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    cin >> m;
    vector<int> x(m);
    for (int i = 0; i < m ; i++) cin >> x[i];

    bool ok = 1;
    for (int i = 0; i < n && ok; i++) if (a[i] < b[i]) ok = 0;
    if (!ok) {
        cout << "NO";
        return;
    }
    vector<reference_wrapper<vector<int>>> arrs = {a, b, x};
    compress(arrs);
    map<int, int> raz_cnt;
    for (auto &e: x) raz_cnt[e]++;

    int sz = *max_element(b.begin(), b.end());
    SGT sgt(sz + 1);
    map<int, int> lst;
    for (int i = 0; i < n && ok; i++) {
        sgt.update(b[i], i);
        if (a[i] == b[i]) continue;
        if (lst.count(b[i]) == 0 || lst[b[i]] < sgt.query(b[i] + 1, sz)) {
            if (--raz_cnt[b[i]] < 0) ok = 0;
            lst[b[i]] = i;
        }
    }
    cout << (ok ? "YES" : "NO");
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
