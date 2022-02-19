#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
//================================================================

int solve() {
    int n;
    cin >> n;
    vector<int> a(n), mx(n, 0);
    vector<bool> in(n, true);
    for (auto &e: a) cin >> e;

    for (int i = 1; i < n; i++) {
        mx[i] = max(mx[i - 1], a[i - 1]);
        if (a[i] <= mx[i]) in[i] = false;
    }
    indexed_set<int> st;
    int res = n;
    for (int i = n - 1 ; i >= 0; i--) {
        if (!in[i]) {
            st.insert(a[i]);
            continue;
        }
        int x = st.order_of_key(a[i]), y = st.order_of_key(mx[i]);
        if (y != 0) {
            res -= x - y + 1;
        }
        else res -= x;
        st.insert(a[i]);
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
        cout << solve() << '\n';
    }
    return 0;
}