// given sizes of n cubes return min number of towers
// only a smaller cube can go on top of another cube

#include <bits/stdc++.h>
using namespace std;

int solve() {

    int n, x;
    cin >> n;
    multiset<int> st;
    while (n--) {
        cin >> x;
        auto itr = st.upper_bound(x);
        if (itr != st.end()) st.erase(itr);
        st.insert(x);
    }
    return st.size();
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    // cin >> T;
    while (T--) {
        cout << solve();
    }
    return 0;
}