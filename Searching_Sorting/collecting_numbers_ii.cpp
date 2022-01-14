// continuation to collecting numbers
// return # rounds after each of m swaps

#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n, m;
    cin >> n >> m;
    int arr[n + 1], idx[n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        idx[arr[i]] = i;
    }
    idx[0] = 0;
    idx[n + 1] = n + 1;
    int res = 1;
    for (int i = 1; i <= n; i++) res += idx[arr[i]] > idx[arr[i] + 1];

    while (m--) {
        int a, b;
        cin >> a >> b;
        if (b < a) swap(a, b);

        // |arr[a] - arr[b]| = 1 condition to keep in mind

        if (a < idx[arr[a] - 1] && idx[arr[a] - 1] <= b) res--;
        if (a < idx[arr[a] + 1] && idx[arr[a] + 1] <= b) res++;
        if (a < idx[arr[b] - 1] && idx[arr[b] - 1] < b) res++;
        if (a < idx[arr[b] + 1] && idx[arr[b] + 1] < b) res--;

        cout << res << '\n';

        swap(arr[a], arr[b]);
        idx[arr[a]] = a, idx[arr[b]] = b;
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