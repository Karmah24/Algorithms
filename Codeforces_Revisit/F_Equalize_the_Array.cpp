#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> freq(n + 1, 0);
    for (auto &[k, v]: cnt) freq[v]++;
    for (int i = n - 1; i > 0; i--) freq[i] += freq[i + 1];
    int res = n;
    for (int i = 1; i <= n && freq[i] > 0; i++) {
        res = min(res, n - (freq[i] * i));
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
        cout << solve();
        cout << '\n';
    }
    return 0;
}