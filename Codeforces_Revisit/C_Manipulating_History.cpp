#include <bits/stdc++.h>
using namespace std;
//================================================================

char solve() {
    
    int n;
    cin >> n;
    vector<int> freq(26, 0);
    string s;

    for (int i = 0; i < 2 * n + 1; i++) {
        cin >> s;
        for (auto &ch: s) freq[ch - 'a']++;
    }
    int i = 0;
    while (freq[i] % 2 == 0) i++;
    return 'a' + i;
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