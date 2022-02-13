#include <bits/stdc++.h>
using namespace std;
// #define int long long
//================================================================

int solve() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    float k = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int x = (s[i] - '0') * pow(10, floor(k));
        if (i % 2 == 0) a += x;
        else b += x;
        k += 0.5;
    }
    return (a + 1) * (b + 1) - 2;
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