#include <bits/stdc++.h>
using namespace std;
#define int long long
//=======================
int n;
vector<int> a, b;

bool check(int x) {

    int k = 1;
    for (int i = 0; i < n && k <= x; i++) {
        if (a[i] >= x - k && b[i] >= k - 1) k++;
    }
    return k > x;
}
int solve() {

    cin >> n;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    int lo = 1, hi = n, res = 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}