#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {
    
    int k;
    cin >> k;
    vector<int> cnt(10, 1);
    int x = 1;
    for (int i = 0; x < k; i = (i + 1) % 10) {
        x /= cnt[i];
        x *= ++cnt[i];
    }
    string s = "codeforces";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < cnt[i]; j++) cout << s[i];
    }
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}