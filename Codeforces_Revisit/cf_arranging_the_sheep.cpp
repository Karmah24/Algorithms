#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

ll solve() {

    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (str[i] == '*') pos.push_back(i);
    }
    int m = pos.size() / 2;
    ll res = 0;
    for (int i = 0; i < pos.size(); i++) {
        res += abs(int(pos[i] - (pos[m] - m + i)));
    }
    return res;
}
int main() {
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