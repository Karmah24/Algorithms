#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
//================================================================

void testcase() {

    int n, x;
    cin >> n >> x;

    int m = 0;
    int a, b, prv_a;
    bool ok = 1;
    for (int i = 63; i >= 0; i--) {
        a = (n >> i) & 1LL, b = (x >> i) & 1LL;
        if (a == b) {
            m |= a * (1LL << i);
            prv_a = a;
            continue;
        }
        if ((x >> i) * (1LL << i) != x || b > a || prv_a == 1) ok = 0;
        else {
            m |= (1LL << (i + 1));
        }
        break;
    }
    cout << (ok && m >= n ? m : -1);
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
