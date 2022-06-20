#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

void solve() {

    int n;
    cin >> n;
    vector<int> a(n), res(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> st;
    for (int i = 0; i < n; i++) st.insert(i + 1);

    for (int i = 0; i < n; i++) {

        if (a[i] == i + 1) {
            res[i] = *(next(st.begin()));
            st.erase(next(st.begin()));
        }
        else {
            res[i] = i + 1;
            st.erase(i + 1);
        }
    }
    for (auto &e: res) cout << e << " ";
    cout << '\n';
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