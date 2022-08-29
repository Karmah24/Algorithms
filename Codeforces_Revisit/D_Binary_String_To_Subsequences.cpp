#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {

    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> end(2);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {

        int c = s[i] - '0';
        int cnt = end[0].size() + end[1].size();

        if (end[1 - c].empty()) {
            end[c].push_back(cnt + 1);
        }
        else {
            end[c].push_back(end[1 - c].back());
            end[1 - c].pop_back();
        }
        res[i] = end[c].back();
    }
    cout << end[0].size() + end[1].size() << "\n";
    for (auto &e: res) cout << e << " ";
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
        solve();
        cout << '\n';
    }
    return 0;
}