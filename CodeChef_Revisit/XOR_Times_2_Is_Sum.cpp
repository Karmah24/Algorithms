#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {
    
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        st.insert(arr[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {

        int a = arr[i];
        int x = 0, b = 0, p = 1;
        for (int i = 0; i < 62; i++) {

            if (((a & p) > 0) ^ x) b += p;
            x = ((a & p) > 0) & ((b & p) > 0);
            p = p << 1;
        }
        if (st.count(b)) res++;
    }
    return res / 2;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        cout << solve();
        cout << '\n';
    }
    return 0;
}