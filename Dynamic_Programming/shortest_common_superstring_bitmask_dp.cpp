#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
//================================================================

// cost of going from string a to b
// if b is a substring of a then cost is 0
// else we need to append chars left after lps
// longest substr which is a prefix of b and suffix of a
int solve(string &a, string &b) { 

	string s = b + "$" + a;
	int n = s.size();
	vector<int> lps(n, -1);
	lps[0] = 0;
	for (int i = 1; i < n; i++) {

		int l = lps[i - 1];
		while (l > 0 && s[i] != s[l]) l = lps[l - 1];
		if (s[i] == s[l]) l++;
		lps[i] = l;
	}
	if (*max_element(lps.begin(), lps.end()) == b.size()) return 0;
	else return b.size() - lps[n - 1];
}

int n;
vector<string> words;
vector<vector<int>> cost, dp, path;

// travelling salesman problem
int tsp(int u, int mask) {

	
	int &res = dp[u][mask];
	int &nxt = path[u][mask];
	if (res != -1) return res;
	if (mask == (1 << n) - 1) return res = 0;

	res = INF;
	for (int v = 0; v < n; v++) {

		if ((mask & (1 << v)) == 0) {
			
			int curr = cost[u][v] + tsp(v, mask | (1 << v));

			if (res > curr) {
				res = curr;
				nxt = v;
			}
		}
	}
	return res;
}

string construct_path(int u, int mask) {

	int v = path[u][mask];
	if (v == -1) return "";
	int c = dp[u][mask] - dp[v][mask | (1 << v)];

	string sfx = words[v].substr(words[v].size() - c, c);
	return sfx + construct_path(v, mask | (1 << v));

}

void testcase() {

	cin >> n;
	words.resize(n);
	for (int i = 0; i < n; i++) cin >> words[i];

	cost.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			cost[i][j] = solve(words[i], words[j]);
		}
	}

	string res;
	int len = INF;
	for (int u = 0; u < n; u++) {

		dp.assign(n, vector<int>(1 << n, -1));
		path.assign(n, vector<int>(1 << n, -1));

		tsp(u, 1 << u);
		string curr = words[u] + construct_path(u, 1 << u);
		if (curr.size() < len) {

			len = curr.size();
			res = curr;
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
    // cin >> T;
    while (T--) {
        testcase();
        cout << '\n';
    }
    return 0;
}
