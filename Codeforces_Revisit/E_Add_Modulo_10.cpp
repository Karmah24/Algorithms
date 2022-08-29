#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

bool solve() {

    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    };

    bool div_by_5 = false, ndiv_by_5 = false;
    set<int> st2;
    for (auto &e: st) {

        if (e % 5 == 0) {
            div_by_5 = true;
            if (e % 10 == 5) st2.insert(e + 5);
            else st2.insert(e);
        }
        else {
            ndiv_by_5 = true;
            int x = e;
            while (x % 10 != 2) x += x % 10;
            st2.insert(x);
        }
    }
    if (div_by_5 && ndiv_by_5) return false;
    if (div_by_5) return st2.size() == 1;
    int p = *st2.begin();
    for (auto &e: st2) {
        if ((e - p) % 20 != 0) return false;
        p = e;
    }
    return true;
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
		if (solve()) cout << "Yes";
        else cout << "No";
		cout << '\n';
	}
	return 0;
}