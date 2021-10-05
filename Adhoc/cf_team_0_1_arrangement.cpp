#include <bits/stdc++.h>
using namespace std;

#define ll long long
//=======================

void solve() {
    
    int m, n;
    cin >> m >> n;

    if (m > n + 1 || n > 2 * (m + 1)) {
        cout << -1;
        return;
    }
    while (m && n > m) {

        cout << "110";
        n -= 2;
        m--;
    }
    string s;
    if (n >= m) s = "10";
    else s = "01";
    while (n && m) {
        cout << s;
        n--, m--;
    }
    while (n) {
        cout << "1";
        n--;
    }
    while (m) {
        cout << "0";
        m--;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while (T--) {
        
        solve();
    }
    return 0;
}