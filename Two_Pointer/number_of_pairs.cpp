// given l, r & a(n) find all ordered pairs : (l <= a[i] + a[j] <= r)
// find all pairs : (a[i] + a[j] <= r) - all pairs : (a[i] + a[j] < l)

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {

    ll res = 0;
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] <= r) {
            res += j - i;   // all pairs (a[i], a[k])  k : i + 1 -> j
            i++;
        }
        else j--;   // no pair possible with a[j]
    }
    i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] < l) {
            res -= j - i;
            i++;
        }
        else j--;
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}