// given arr[n] return the smallest sum not a subset sum

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve() {
    
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    // 1 + 2 + 3 +...n = n(n + 1) / 2 = s
    // 2 + ...  + n = n - 1
    // 1 + 3 ... + n = s - 2
    // 1 + ... + x - 1 + x + 1 ... + n = s - x
    // ...
    // therefore all sums till s are possible
    
    ll res = 1;
    for (int i = 0; i < n && arr[i] <= res; i++) res += arr[i];

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