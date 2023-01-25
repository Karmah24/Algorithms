#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

int query(int x, int y) {
    cout << "?" << " " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

int ans(int x, int y) {
    cout << "!" << " " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

void testcase() {

    int n;
    cin >> n;

    set<int> st;
    for (int i = 1; i < n + 1; i++) st.insert(i);

    while (st.size() > 2) {

        auto x = st.begin();
        auto y = next(x);
        auto z = next(y);
        int gy = query(*x, *y), gz = query(*x, *z);
        if (gy == gz) st.erase(x);
        else if (gy > gz) st.erase(z);
        else st.erase(y);
    }
    ans(*st.begin(), *st.rbegin());
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	//   freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
	}
	return 0;
}
