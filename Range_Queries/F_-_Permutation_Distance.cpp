// Given a permutation P
// Di = min(|Pi - Pj| + |i - j|) for all j != i.
// Find all Di.

// 4 possible values for Di.
// 1. Pi - Pj + i - j = (Pi + i) + -(Pj + j); i > j, Pi > Pj
// 2. Pj - Pi + i - j = -(Pi - i) + (Pj - j); i > j, Pj > Pi
// 3. Pi - Pj + j - i = (Pi - i) + -(Pj - j); j > i, Pi > Pj
// 4. Pj - Pi + j - i = -(Pi + i) + (Pj + j); j > i, Pj > Pi

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 2e5 + 5;
//================================================================

class SGT {
public:
    int n;
    vector<int> sgt;
    SGT(int n) {

        this->n = n;
        sgt.assign(4 * n, INF);
    }
    int query(int ql, int qr, int sl = 0, int sr = -1, int idx = 0) {
        
        if (sr == -1) sr = n - 1;
        if (ql <= sl && sr <= qr) return sgt[idx];
        if (qr < sl || sr < ql) return INF;
        int mid = (sl + sr) / 2;
        int left = query(ql, qr, sl, mid, idx * 2 + 1);
        int right = query(ql, qr, mid + 1, sr, idx * 2 + 2);
        return min(left, right);
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
        sgt[idx] = min(sgt[2 * idx + 1], sgt[2 * idx + 2]);
    }
    void clear() {
        sgt.assign(4 * n, INF);
    }
};

void testcase() {

    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i < n + 1; i++) cin >> p[i];

    SGT sgt1(n + 1), sgt2(n + 1); // -(Pi + i), (Pi - i)
    vector<int> res(n + 1);

    // 1. Pi - Pj + i - j = (Pi + i) + -(Pj + j); i > j, Pi > Pj
    // 2. Pj - Pi + i - j = -(Pi - i) + (Pj - j); i > j, Pj > Pi
    for (int i = 1; i < n + 1; i++) {

        int op1 = sgt1.query(0, p[i] - 1);
        int op2 = sgt2.query(p[i] + 1, n);
        res[i] = min(op1 + p[i] + i, op2 - (p[i] - i));
        sgt1.update(p[i], -(p[i] + i));
        sgt2.update(p[i], p[i] - i);
    }
    sgt1.clear(), sgt2.clear(); // -(Pi - i), (Pi + i)

    // 3. Pi - Pj + j - i = (Pi - i) + -(Pj - j); j > i, Pi > Pj
    // 4. Pj - Pi + j - i = -(Pi + i) + (Pj + j); j > i, Pj > Pi
    for (int i = n; i >= 1; i--) {

        int op1 = sgt1.query(0, p[i] - 1);
        int op2 = sgt2.query(p[i] + 1, n);
        res[i] = min({res[i], op1 + p[i] - i, op2 - (p[i] + i)});
        sgt1.update(p[i], -(p[i] - i));
        sgt2.update(p[i], p[i] + i);
    }
    for (int i = 1; i < n + 1; i++) cout << res[i] << " ";
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
