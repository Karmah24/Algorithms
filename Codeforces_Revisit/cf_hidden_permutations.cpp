#include <bits/stdc++.h>
using namespace std;
//================================================================

int query(int i) {
    int res;
    cout << "? " << i << endl;
    cin >> res;
    return res;
}
void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1, -1);

    for (int i = 1; i < n + 1; i++) {
        if (p[i] != -1) continue;
        vector<int> cycle;
        int head = query(i), curr = -1;
        while (curr != head) {
            curr = query(i);
            cycle.push_back(curr);
        }
        for (int j = 0; j < cycle.size(); j++) {
            p[cycle[j]] = cycle[(j + 1) % cycle.size()];
        }
    }
    cout << "! ";
    for (int i = 1; i < n + 1; i++) cout << p[i] << " ";
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}