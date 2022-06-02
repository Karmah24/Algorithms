#include <bits/stdc++.h>
using namespace std;
//================================================================

pair<int, int> simplify(pair<int, int> &curr) {
    int _gcd = gcd(curr.first, curr.second);
    return {curr.first / _gcd, curr.second / _gcd};
}
vector<int> solve() {
    
    int n;
    string s;
    cin >> n >> s;
    map<pair<int, int>, int> mp;
    pair<int, int> curr = {0, 0};
    vector<int> res;

    for (auto &ch: s) {

        if (ch == 'D') curr.first++;
        else curr.second++;

        res.push_back(++mp[simplify(curr)]);
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
        for (auto &e: solve()) cout << e << ' ';
        cout << '\n';
    }
    return 0;
}