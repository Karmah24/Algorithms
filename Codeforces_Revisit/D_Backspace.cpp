#include <bits/stdc++.h>
using namespace std;
//================================================================

bool solve() {
    
    string t, s;
    cin >> s >> t;

    int i = t.size() - 1, j = s.size() - 1;
    
    while (i >= 0 && j >= 0) {

        if (s[j] == t[i]) j--, i--;
        else j -= 2;
    }
    return i < 0;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}