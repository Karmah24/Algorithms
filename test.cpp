#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

ll solve() {

    string s = to_string(5) + " " + to_string(8);
    cout << s << '\n';
    return 24;
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

        cout << solve() << '\n';
    }
    return 0;
}