#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    int l, n, x;
    cin >> l >> n;

    set<int> lights;
    lights.insert(0);
    lights.insert(l);
    multiset<int> darkDis;
    darkDis.insert(l);

    while (n--) {

        cin >> x;
        lights.insert(x);
        auto itr = lights.find(x);
        darkDis.erase(darkDis.find(*next(itr) - *prev(itr)));
        darkDis.insert(*next(itr) - x);
        darkDis.insert(x - *prev(itr));

        cout << *prev(darkDis.end()) << " ";
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