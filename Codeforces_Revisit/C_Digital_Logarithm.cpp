#include <bits/stdc++.h>
using namespace std;
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

    int n, x;
    cin >> n;
    priority_queue<int> a, b;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        b.push(x);
    }
    int res = 0;
    while (!(a.empty() && b.empty())) {

        int p = a.top(), q = b.top();
        if (p == q) {
            a.pop();
            b.pop();
            continue;
        }
        res++;
        if (p > q) {
            a.pop();
            a.push(dig(p));
        }
        else {
            b.pop();
            b.push(dig(q));
        }
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
