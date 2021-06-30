// given n ticket prices and m buyer bids
// return max ticket price for each buyer

#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n, m, x;
    cin >> n >> m;
    multiset<int> tp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        tp.insert(x);
    }
    while (m--) {
        int cp;
        cin >> cp;
        auto ub = tp.upper_bound(cp); // different from stl upper_bound
        if (ub == tp.begin()) cout << -1 << '\n';
        else {
            ub--;
            cout << *ub << '\n';
            tp.erase(ub);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}