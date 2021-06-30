#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using indexed_set = tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update>;

void solve() {

    int n, k;
    cin >> n >> k;

    indexed_set<int> st;
    for (int i = 0; i < n; i++) st.insert(i + 1);

    int pos = 0;
    while (!st.empty()) {
        
        pos = (pos + k) % st.size();
        auto itr = st.find_by_order(pos);
        cout << *itr << " ";
        st.erase(itr);
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