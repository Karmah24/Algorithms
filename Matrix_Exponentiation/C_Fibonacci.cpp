#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

struct Matrix {
    int a[2][2] = {0};
    Matrix operator *(Matrix &other) {
        Matrix product;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    product.a[i][k] += a[i][j] * other.a[j][k];
                    product.a[i][k] %= MOD;
                }
            }
        }
        return product;
    }
};

Matrix mpow(Matrix m, int n) {
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
    cin >> n;
    if (n == 0) {
        cout << 0;
        return;
    }

    // simple dp
    // vector<int> dp{0, 1};
    // for (int i = 2; i < n + 1; i++) {
    //     int a = 0 * dp[0] + 1 * dp[1];
    //     int b = 1 * dp[0] + 1 * dp[1];
    //     a %= MOD, b %= MOD;
    //     dp = {a, b};
    // }
    // cout << dp[1];

    Matrix single;
    single.a[0][0] = 0;
    single.a[0][1] = 1;
    single.a[1][0] = 1;
    single.a[1][1] = 1;

    Matrix total = mpow(single, n - 1);
    int a = 0, b = 1;
    int final_a = a * total.a[0][0] + b * total.a[1][0];
    int final_b = a * total.a[0][1] + b * total.a[1][1];
    final_a %= MOD, final_b %= MOD;
    cout << final_b;
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
