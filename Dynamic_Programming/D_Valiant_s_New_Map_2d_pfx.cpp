#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int N = 1e5 + 5;
//================================================================

int n, m;
vector<vector<int>> grid;
vector<vector<int>> pfx;

void convert_grid(int x) {

    pfx = grid;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) pfx[i][j] = grid[i][j] >= x;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            pfx[i][j] += pfx[i - 1][j] + pfx[i][j - 1];
            pfx[i][j] -= pfx[i - 1][j - 1];
        }
    }
}
int subgrid_sum(int i1 ,int j1, int i2, int j2) {

    int res = pfx[i2][j2];
    res -= pfx[i1 - 1][j2] + pfx[i2][j1 - 1];
    res += pfx[i1 - 1][j1 - 1];
    return res;
}
bool check(int x) {

    convert_grid(x);

    for (int i = 1; i + x - 1 < n + 1; i++) {
        for (int j = 1; j + x - 1 < m + 1; j++) {
            int ni = i + x - 1, nj = j + x - 1;
            if (subgrid_sum(i, j, ni, nj) == x * x) return 1;
        }
    }
    return 0;
}
void testcase() {

    cin >> n >> m;
    grid.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) cin >> grid[i][j];
    }
    int lo = 1, hi = min(n, m), res = 1;
    while (lo <= hi) {

        int mid = (lo + hi) / 2;
        if (check(mid)) {

            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
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
	cin >> T;
	while (T--) {
		testcase();
		cout << '\n';
	}
	return 0;
}
