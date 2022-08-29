#include <bits/stdc++.h>
using namespace std;
//================================================================

int pairs(int x, unordered_map<int, int> &mp, vector<int> &a) {

    int res = 0, n = a.size();
    for (int i = 1; (i <= n) && (a[i] * a[i]) < x; i++) {

        if (x % a[i] != 0 || mp.count(x / a[i]) == 0) continue;
        if ((mp[a[i]] + mp[x / a[i]]) == x) res++;
    }
    return res;
}
int solve() {
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    unordered_map<int, int> mp;
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 3; i < 2 * n; i++) {
        res += pairs(i, mp, a);
    }
    return res;
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
        cout << solve();
        cout << '\n';
    }
    return 0;
}