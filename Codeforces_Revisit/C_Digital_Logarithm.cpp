#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 5;
//================================================================

int dig(int n) {
    int d = 0;
    while (n) {
        d++;
        n /= 10;
    }
    return d;
}
void testcase() {

	int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> m1, m2;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m1[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        m2[b[i]]++;
    }
    int res = 0;
    map<int, int> x, y;
    for (auto &[k, v]: m1) {

        if (k <= 9) {
            x[k] = v;
            continue;
        }
        if (m1[k] >= m2[k]) {
            res += m1[k] - m2[k];
            x[dig(k)] += m1[k] - m2[k];
            m2[k] = 0;
        }
        else m2[k] -= m1[k];
    }
    for (auto &[k, v]: m2) {
        
        if (v == 0) continue;
        if (k > 9) {
            res += v;
            y[dig(k)] += v;
        }
        else y[k] = v;
    } 
    for (int i = 2; i <= 9; i++) {
        res += abs(x[i] - y[i]);
    }
    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
