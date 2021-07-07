#include <bits/stdc++.h>
using namespace std;


void solve() {
    
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    vector<bool> res(n);
    res[0] = (s[0] == s[1] || s[0] == s[n - 1]);

    for (int i = 1; i < n - 2; i++) {
        res[i] = s[i] == (s[i - 1] || s[i] == s[i + 1]);
    } 
    res[n - 1] = (s[n - 1] == s[n - 2] || s[n - 1] == s[0]);

    for (int i = 0; i < n; i++) {
        if (res[i]) cout << s[i];
        else if (s[i] == 'B') cout << 'W';
        else cout << 'B';
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}