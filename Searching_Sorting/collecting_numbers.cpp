// given arr[n] collect all number in increasing order
// return minimum number of rounds required

#include <bits/stdc++.h>
using namespace std;

int solve() {
    
    int n;
    cin >> n;
    int arr[n], idx[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        idx[--arr[i]] = i;
    }
    idx[n] = n;
    int res = 1;
    for (int i = 0; i < n; i++) res += idx[arr[i]] > idx[arr[i] + 1];
    // for every arr[i] : idx[arr[i]] > idx[arr[i] + 1]
    // 1 round has to be made before collecting arr[i]

    return res;
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