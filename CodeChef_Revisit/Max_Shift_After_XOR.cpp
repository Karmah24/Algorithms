#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    a.insert(a.end(), a.begin(), a.end()); // cyclic shifting

    int x = 0;
    for (int i = 0; i < 2 * n; i++) {
        x ^= a[i];
        a[i] = x;
    }
    unordered_map<int, int> cnt;
    int i = 0;
    for (;i < n; i++) cnt[a[i]]++;
    int res = cnt.size();
    while (i < (2 * n)) {
        if (--cnt[a[i - n]] == 0) cnt.erase(a[i - n]);
        cnt[a[i]]++;
        i++;
        res = max(res, (int)cnt.size());
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