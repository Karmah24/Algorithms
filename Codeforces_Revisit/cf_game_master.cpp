#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================

vector<bool> solve() {

    int n;
    cin >> n;
    vector<vector<int>> powers(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> powers[i][0];
        powers[i][2] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> powers[i][1];
    }
    sort(powers.begin(), powers.end());
    vector<int> s_lg(n);
    s_lg[0] = powers[0][1];
    for (int i = 1; i < n; i++) s_lg[i] = max(s_lg[i - 1], powers[i][1]);
    vector<bool> res(n, 0);
    res[powers[n - 1][2]] = true;
    int min_winnable = powers[n - 1][1];
    for (int i = n - 2; i >= 0; i--) {
        if (s_lg[i] > min_winnable) {
            res[powers[i][2]] = true;
            min_winnable = min(min_winnable, powers[i][1]);
        }
    }
    return res;
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
        for (auto e: solve()) cout << e;
        cout << '\n';
    }
    return 0;
}