#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve() {

    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    ll k, res = 0;
    if (n % 2 != 0) k = arr[n / 2];
    else k = (arr[n / 2] + arr[n / 2 - 1]) / 2;
    for (int i = 0; i < n; i++) res += abs(arr[i] - k);
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