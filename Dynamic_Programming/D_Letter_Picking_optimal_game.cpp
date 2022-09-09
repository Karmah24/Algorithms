#include <bits/stdc++.h>
using namespace std;
//================================================================

void testcase() {

	string s;
    cin >> s;

    int n = s.size();

	vector<vector<bool>> dp(n, vector<bool>(n, 0));

	for (int i = 0; i < n - 1; i++) {
		dp[i][i + 1] = s[i] != s[i + 1];
	}
	for (int i = n - 3; i >= 0; i--) {
		for (int j = i + 2; j < n; j++) {
			
			bool f1 = true, f2 = true;

			// Alice takes i
			if (!dp[i + 1][j - 1] && s[i] >= s[j]) f1 = false;
			if (!dp[i + 2][j] && s[i] >= s[i + 1]) f1 = false;

			// Alice take j
			if (!dp[i][j - 2] && s[j] >= s[j - 1]) f2 = false;
			if (!dp[i + 1][j - 1] && s[j] >= s[i]) f2 = false;

			dp[i][j] = f1 || f2;
		}
	}
	if (dp[0][n - 1]) cout << "Alice";
	else cout << "Draw";
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
