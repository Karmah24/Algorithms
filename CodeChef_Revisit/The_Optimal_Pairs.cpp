#include <bits/stdc++.h>
using namespace std;
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

int solve() {
    
    int n;
    cin >> n;
    int res = 1;
    for (auto &[f, s]: factorize(n)) {
        res *= s + 1;
    }
    return 2 * (res - 1) - (1 - (n % 2));
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}