#include <bits/stdc++.h>
using namespace std;
//================================================================

int solve() {
    
    int n;
    string s, t;
    cin >> n >> s >> t;

    int b = 0, c = 0;
    for (int i = 0; i < n; i++) {

        if (s[i] == t[i]) {
            if (s[i] == 'c' && b > 0) return false;
            if (s[i] == 'a' && c > 0) return false;
            continue;
        };

        if (s[i] != 'b' && t[i] != 'b') return false;

        if (s[i] == 'a') {
            if (c > 0) return false;
            b++;
        }
        else if (s[i] == 'b') {
            if (t[i] == 'c') {
                if (b > 0) return false;
                c++;
            }
            else if (b == 0) return false;
            else b--;
        }
        else {
            if (b > 0) return false;
            if (c == 0) return false;
            else c--;
        }
    }
    return (b == 0 && c == 0);
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