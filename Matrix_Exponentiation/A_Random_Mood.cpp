#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

struct Matrix {
    double a[2][2] = {{0.0, 0.0}, {0.0, 0.0}};
    Matrix operator *(Matrix& other) {
        Matrix product;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    product.a[i][k] += a[i][j] * other.a[j][k];
                }
            }
        }
        return product;
    }
};

Matrix bin_pow(Matrix m, int n) {
    Matrix res;
    for (int i = 0; i < 2; i++) res.a[i][i] = 1;
    while (n) {
        if (n & 1) res = res * m;
        m = m * m;
        n = n >> 1;
    }
    return res;
}

void testcase() {

    int n;
    double p;
    cin >> n >> p;

    // simple dp
    // vector<double> dp{1.0, 0.0}; // dp[0] = happy_prob, dp[1] = sad_prob
    // for (int i = 0; i < n; i++) {
    //
    //     double new_happy = dp[0] * (1 - p) + dp[1] * p;
    //     double new_sad = dp[1] * (1 - p) + dp[0] * p;
    //     dp = {new_happy, new_sad};
    // }

    Matrix single;
    single.a[0][0] = 1 - p; // happy -> happy
    single.a[0][1] = p;     // happy -> sad
    single.a[1][0] = p;     // sad -> happy
    single.a[1][1] = 1 - p; // sad -> sad

    // Matrix total;
    // for (int i = 0; i < 2; i++) total.a[i][i] = 1;
    // for (int i = 0; i < n; i++) {
    //     total = total * single;
    // }
    Matrix total = bin_pow(single, n);
    cout << fixed << setprecision(10) << total.a[0][0];
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		// freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
