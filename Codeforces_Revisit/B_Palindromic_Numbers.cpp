#include <bits/stdc++.h>
using namespace std;
//================================================================

string solve() {
    
    int d;
    string n;
    cin >> d >> n;

    string p = string(d, '0');
    p[d - 1] = '1';
    if (n[0] == '9') p[d - 2] = p[0] = '1';
    // cout << "p: " << p << '\n';
    
    string res = string(d, '0');
    int b = 0;
    for (int i = d - 1; i >= 0; i--) {

        res[i] = p[i] - b - n[i] + '0';
        if (n[i] > p[i] - b) {
            res[i] += 10;
            b = 1;
        }
        else {
            b = 0;
        }
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
        cout << solve() << '\n';
    }
    return 0;
}