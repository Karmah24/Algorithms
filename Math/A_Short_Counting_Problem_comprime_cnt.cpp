#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;8
//================================================================

vector<int> factorize(int n) {
    vector<int> factors;
    if (n % 2 == 0) factors.push_back(2);
    while (n % 2 == 0) n /= 2;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i != 0) continue;
        factors.push_back(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) factors.push_back(n);
    return factors;
}
int solve(vector<int> &factors, int r) {
    int res = 0;
    int n = factors.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        int product = 1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                product *= factors[i];
                cnt++;
            }
        }
        if (cnt & 1) res -= r / product;
        else res += r / product;
    }
    return res;
}
void testcase() {

    int a, b, l, r;
    cin >> a >> b >> l >> r;

    vector<int> fa = factorize(a), fb = factorize(b);
    vector<int> fab = fa;
    fab.insert(fab.end(), fb.begin(), fb.end());
    sort(fab.begin(), fab.end());
    fab.erase(unique(fab.begin(), fab.end()), fab.end());

    int res1 = solve(fa, r) - solve(fa, l - 1);
    int res2 = solve(fb, r) - solve(fb, l - 1);
    int res3 = solve(fab, r) - solve(fab, l - 1);
    cout << res1 + res2 - res3;
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
