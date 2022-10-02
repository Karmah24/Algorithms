#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
//================================================================

int dp[105][10005];
vector<int> a, b;

bool solve(int n, int s) {

    if (s < 0) return 0;
    if (n < 0) return s == 0;
    int &res = dp[n][s];
    if (res != -1) return res;

    res = solve(n - 1, s - a[n]) || solve(n - 1, s - b[n]);
    return res;
}

void get_path(int n, int s, string &path) {

    if (n == 0) {

        if (s == a[n]) path.push_back('H');
        else path.push_back('T');
        return;
    }
    if (s >= a[n] && dp[n - 1][s - a[n]]) {
        
        path.push_back('H');
        get_path(n - 1, s - a[n], path);
    }
    else {

        path.push_back('T');
        get_path(n - 1, s - b[n], path);
    }
}

void testcase() {

    int n, s;
    cin >> n >> s;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    memset(dp, -1, sizeof(dp));
    bool ok = solve(n - 1, s);
    if (ok) cout << "Yes\n";
    else cout << "No";
    if (!ok) return;
    string path = "";
    get_path(n - 1, s, path);
    reverse(path.begin(), path.end());
    cout << path;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
