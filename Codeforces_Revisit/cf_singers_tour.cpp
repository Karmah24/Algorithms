#include <bits/stdc++.h>
using namespace std;
#define int long long
//=======================

void solve() {
    
    int n, B = 0;
    cin >> n;
    vector<int> b(n);
    for (auto &e: b) {
        cin >> e;
        B += e;
    }
    int nn = (n * (n + 1)) / 2;
    int A = B / nn;
    if (B % nn != 0 || A < n) {
        cout << "NO";
        return;
    }
    bool res = true;
    vector<int> a(n);
    int x = A - (b[0] - b[n - 1]);
    if (x % n != 0 || x <= 0) res = false;
    a[0] = x / n;
    for (int i = 1; i < n && res; i++) {
        int x = A - (b[i] - b[i - 1]);
        if (x % n != 0 || x <= 0) res = false;
        a[i] = x / n;
    }
    if (!res) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    for (auto &e: a) cout << e << " ";
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
        solve();
        cout << '\n';
    }
    return 0;
}