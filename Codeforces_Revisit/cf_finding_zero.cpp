#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================

pair<int, int> query(vector<int> &q) {
    vector<pair<int, int>> comp(4);
    for (int j = 0; j < 4; j++) {
        vector<int> x = q;
        x.erase(x.begin() + j);
        int res;
        printf("? %d %d %d\n", x[0], x[1], x[2]);
        fflush(stdout);
        cin >> res;
        comp[j] = {res, q[j]};
    }
    sort(comp.begin(), comp.end());
    return {comp[0].second, comp[1].second};
}
void solve() {
    int n;
    cin >> n;
    vector<int> q;
    pair<int, int> res = {1, 2};
    for (int i = 3; i <= n - 1; i += 2) {
        q = {res.first, res.second, i, i + 1};
        res = query(q);
    }
    if (n % 2 == 1) {
        int idx = 1;
        while (idx == res.first || idx == res.second) idx++;
        q = {res.first, res.second, idx, n};
        res = query(q);
    }
    printf("! %d %d\n", res.first, res.second);
    fflush(stdout);
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
    }
    return 0;
}