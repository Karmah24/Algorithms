#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    
    int n;
    cin >> n;
    vector<int> d;
    int a, b;
    cin >> a >> b;
    while (n--) {
        d.push_back(b - a);
        a = b;
        cin >> b;
    }
    bool inc;
    for (int i = 1; i < d.size(); i++) {

        if (abs(d[i] - d[i - 1]) > 4) {
            cout << -1;
            return;
        }
        if (d[i] == d[i - 1]) continue;
    
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