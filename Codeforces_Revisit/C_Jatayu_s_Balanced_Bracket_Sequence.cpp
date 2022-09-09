#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 5;
//================================================================

void testcase() {

	int n;
    string s;
    cin >> n >> s;
    n *= 2;
    
    map<int, int> mp;
    stack<int> st;

    int res = 0;
    st.push(-1);
    for (int i = 0; i < n; i++) {

        if (s[i] == '(') {
            st.push(i);
            res++;
        }
        else {
            st.pop();
            mp[st.top()]++;
        }
    }
    for (auto &[k, v]: mp) res -= v - 1;
    cout << res; 
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
