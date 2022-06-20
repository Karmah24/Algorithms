#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

string solve() {
    
    int n, x;
    cin >> n >> x;

    if (n % 2 == 0) {
        if (x > n / 2) return "-1";
    }
    else if (x > n / 2 + 1) return "-1";

    string res(n, 'a');
    char ch = 'b';
    int i = 0;
    for (int tt = 0; tt < x - 1; tt++, ch++, i++) {

        res[i] = res[n - 1 - i] = ch;
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