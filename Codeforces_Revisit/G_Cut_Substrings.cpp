#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9 + 5;

#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) { return ((x % MOD) + (y % MOD)) % MOD; }
//================================================================

string s, t;
int n, m;
bool match[505];

void lps() {

    string str = t + "$" + s;
    vector<int> pi(str.size());
    pi[0] = 0;
    for (int i = 1; i < str.size(); i++) {

        int l = pi[i - 1];
        while (l > 0 && str[i] != str[l]) l = pi[l - 1];
        if (str[i] == str[l]) l++;
        pi[i] = l;
        if (l == m) match[i - 2 * m] = true;
    }
}

pair<int, int> neg = {-1, -1};
pair<int, int> dp[505];

pair<int, int> solve(int i) {

    auto &res = dp[i];
    if (res != neg) return res;
    if (i == n) return res = {0, 1};

    if (!match[i]) return res = solve(i + 1);

    res = {INF, 0};
    for (int j = 0; j < m; j++) {

        if (!match[i + j]) continue;
            
        auto curr = solve(i + j + m);
        curr.first++;
        if (curr.first < res.first) res = curr;
        else if (curr.first == res.first) {
            
            res.second = add(res.second, curr.second);
        }
    }
    return res;
}

void testcase() {

    cin >> s >> t;
    n = s.size(), m = t.size();

    memset(match, 0, sizeof(match));
    lps();
    for (int i = 0; i <= n; i++) dp[i] = neg;
    solve(0);
    cout << dp[0].first << " " << dp[0].second;
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
