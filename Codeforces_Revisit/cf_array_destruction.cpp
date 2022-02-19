#include <bits/stdc++.h>
using namespace std;
//================================================================

void solve() {
    int n, x;
    cin >> n;
    n *= 2;
    vector<int> arr(n);
    multiset<int> st, st2;
    for (auto &e: arr) {
        cin >> e;
        st.insert(e);
    }
    sort(arr.begin(), arr.end());
    int res = -1;
    for (int i = 0; i < n - 1; i++) {
        st2 = st;
        st2.erase(st2.find(arr[n - 1]));
        st2.erase(st2.find(arr[i]));
        x = arr[n - 1];
        while (!st2.empty()) {
            auto last = (prev(st2.end()));
            st2.erase(last);
            auto itr = st2.find(x - *last);
            if (itr == st2.end()) break;
            st2.erase(itr);
            x = *last;
        }
        if (st2.empty()) {
            res = i;
            break;
        }
    }
    if (res == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    x = arr[n - 1] + arr[res];
    cout << x << '\n';
    st2 = st;
    while (!st2.empty()) {
        int last = *(prev(st2.end()));
        st2.erase(st2.find(x - last));
        st2.erase(st2.find(last));
        cout << x - last << " " << last << '\n';
        x = last;
    }
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
        solve();
    }
    return 0;
}