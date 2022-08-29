#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {

    string n;
    int k;
    cin >> n >> k;

    int s = 0;
    for (int i = 0; i < n.size(); i++) s += n[i] - '0';
    
    int res = 0, x = 0;
    for (int i = n.size() - 1; i >= 0 && s - k > 0; i--) {

        res += pow(10, x) * (10 - (n[i] - '0'));
        s -= n[i] - '0' - 1;
        if (i != 0) n[i - 1]++;
        x++;
    }
    return res;
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
        cout << solve();
        cout << '\n';
    }
    return 0;
}