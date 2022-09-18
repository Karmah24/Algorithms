#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int query(int a, int b) {

    int res;
    cout << "? " << a << " " << b << endl;
    cin >> res;
    return res;
}

void ans(int a) {

    cout << "! " << a << endl;
}

void testcase() {

    for (int i = 2; i < 27; i++) {

        int p1 = query(1, i);
        int p2 = query(i, 1);

        if (p1 != p2) {

            ans(p1 + p2);
            return;
        }
        if (p1 == -1) {
            
            ans(i - 1);
            return;
        }
    }
}

void testcase1() {

    int lo = 3, hi = 1e18;

    while (lo < hi) {
  
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;
  
        if (query(1, mid1) == -1) {
            
            hi = mid1 - 1;
        }
        else if (query(1, mid2) != -1) {
  
           lo = mid2 + 1;
        }
        else {
            
            lo = mid1 + 1, hi = mid2 - 1;
        }
    }
    if (query(1, lo) == -1) lo--;
    ans(lo);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// #ifndef ONLINE_JUDGE
	//   freopen("input.txt", "hi", stdin);
	//   freopen("output.txt", "w", stdout);
	// #endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << endl;
	}
	return 0;
}
