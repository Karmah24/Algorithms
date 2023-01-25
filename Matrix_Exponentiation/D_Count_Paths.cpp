#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
//================================================================

vector<pair<int, int>> edges;

void testcase1() {

    int n, m, k;
    cin >> n >> m >> k;
    edges.clear();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.push_back({u, v});
    }
    vector<int> dp(n, 1);
    for (int i = 0; i < k; i++) {
        vector<int> new_dp(n, 0);
        for (auto &[u, v]: edges) {
            new_dp[v] += dp[u];
            new_dp[v] %= MOD;
        }
        dp = new_dp;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += dp[i];
        res %= MOD;
    }
    cout << res;
}


int n;

struct Matrix {
    int a[100][100] = {0};
    Matrix operator *(Matrix &other) {
        Matrix product;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    product.a[i][k] += a[i][j] * other.a[j][k];
                    product.a[i][k] %= MOD;
                }
            }
        }
        return product;
    }
};

Matrix mpow(Matrix m, int k) {
    Matrix res;
    for (int i = 0; i < n; i++) res.a[i][i] = 1;
    while (k) {
        if (k & 1) res = res * m;
        m = m * m;
        k = k >> 1;
    }
    return res;
}

void testcase() {

    int m, k;
    cin >> n >> m >> k;
    
    Matrix single;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        single.a[u][v] = 1;
    }
    Matrix total = mpow(single, k);
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res += total.a[i][j];
            res %= MOD;
        }
    }
    cout << res;
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
