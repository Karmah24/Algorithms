#include <bits/stdc++.h>
using namespace std;
//================================================================

int n;
vector<vector<double>> prob;
vector<double> dp;

// prob of fish i being killed by one of the other fish in mask
double death_prob(int i, int mask) {

    int k = __builtin_popcountll(mask); // # fish alive
    double res = 0;
    for (int j = 0; j < n; j++) {

        if (mask & (1 << j)) res += prob[j][i]; 
    }
    return (res * 2) / (k * (k - 1)); // res / kC2
}

// mask represents fishes we want alive
// returns probablity of getting the mask
double solve(int mask) {

    double &res = dp[mask];
    if (res > -0.9) return res;
    if (mask == (1 << n) - 1) return res = 1;

    res = 0;

    for (int i = 0; i < n; i++) {

        if (mask & (1 << i)) continue; // we need ith fish alive

        // we need ith fish dead
        // solve(prev_mask) = prob of having required + ith fish alive
        // death_prob(i, prev_mask) = prob of death of fish i
        int prev_mask = mask | (1 << i); 
        res += solve(prev_mask) * death_prob(i, prev_mask);
    }
    return res;
}

void testcase() {

    cin >> n;

    prob.assign(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> prob[i][j];
    }

    dp.assign(1 << n, -1);
    for (int i = 0; i < n; i++) {

        cout << fixed << setprecision(6) << solve(1 << i) << " ";
    }
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
