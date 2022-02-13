#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
#define int long long
//=======================

int solve() {
    int n, x, res = 0;
    cin >> n >> x;
    indexed_set<pair<int, int>> st;
    st.insert({x, 0});
    for (int i = 1; i < n; i++) {
        cin >> x;
        int l = st.order_of_key({x, 0});
        int g = i - st.order_of_key({x, i});
        res += min(l, g);
        st.insert({x, i});
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