#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 5;
//================================================================

void testcase() {

    int n;
	cin >> n;

    if (n % 4 == 0) {
        for (int i = 0; i < n; i++) cout << i << " ";
    }
    else if (n % 4 == 1) {
        cout << "0 ";
        for (int i = 1; i < n; i++) cout << i + 1 << " ";
    }
    else if (n % 4 == 2) {
        cout << "2 1 3 4 12 8 ";
        for (int i = 6; i < n; i++) cout << 8 + i << " ";
    }
    else {
        cout << "2 1 3 ";
        for (int i = 3; i < n; i++) cout << 3 + i << " ";
    }
}
signed main() {
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