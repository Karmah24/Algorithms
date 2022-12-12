#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

vector<pair<int, int>> factorize(int n) {

    vector<pair<int, int>> factors;
    int cnt = 0;
    while (n % 2 == 0) {
        cnt++;
        n /= 2;
    }
    if (cnt > 0) factors.push_back({2, cnt});
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i != 0) continue;
        cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        factors.push_back({i, cnt});
    }
    if (n != 1) factors.push_back({n, 1});
    return factors;
}

int check(int mid, int f, int cnt) {

    int x = 0;
    int ff = f;
    while (ff <= mid) {
        x += mid / ff;
        ff *= f;
    }
    return x >= cnt;
}

int func(int f, int cnt) {

    int lo = 1, hi = f * cnt, res = f * cnt;
    while (lo <= hi) {
    
        int mid = (lo + hi) / 2;
        if (check(mid, f, cnt)) {
    
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return res;
}

void testcase() {

    int k;
    cin >> k;

    vector<pair<int, int>> factors = factorize(k);
    int res = 0;
    for (auto &[factor, cnt]: factors) {

        int x = func(factor, cnt);
        res = max(res, x);
    }
    cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	#ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
	#endif

	int T = 1;
	// cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
