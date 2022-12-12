#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

void testcase() {

    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i++) a[i] = s[i - 1] - '0';

    vector<int> pfx(n + 1, 0);
    for (int i = 1; i < n + 1; i++) pfx[i] = pfx[i - 1] + a[i];

    map<int, int> cnt;
    cnt[0] = 1;
    for (int i = 1; i < n + 1; i++) cnt[pfx[i] - i]++;
    int res = 0;
    for (auto &[k, v]: cnt) res += (v * (v - 1)) / 2;
    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
