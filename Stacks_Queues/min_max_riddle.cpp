// given arr[n] return max of min of all possible window sizes
// variation of largest rectangle in histogram

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    // find the largest window size for which each element is the min

    vector<ll> res(n, LLONG_MIN);
    stack<ll> st;
    st.push(-1);
    int i = 0;
    while (i < n) {
        if (st.top() == -1 || arr[st.top()] <= arr[i]) st.push(i++);
        else {
            int tp = st.top();
            st.pop();
            int curr = i - st.top() - 1;
            res[curr - 1] = max(res[curr - 1], arr[tp]);
        }
    }
    while (st.top() != -1) {
        int tp = st.top();
        st.pop();
        int curr = n - st.top() - 1;
        res[curr - 1] = max(res[curr - 1], arr[tp]);
    }
    for (int i = n - 2; i >= 0; i--) {
        res[i] = max(res[i], res[i + 1]);
    }
    for (int i = 0; i < n; i++) cout << res[i] << " ";
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