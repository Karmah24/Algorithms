#include <bits/stdc++.h>
using namespace std;
//================================================================

int solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &e: arr) cin >> e;

    int res = 2 * n - 1;
    for (int i = 0; i < n - 2; i++) {
        if (arr[i] == arr[i + 1] || arr[i + 1] == arr[i + 2]) continue;
        bool f = arr[i] < arr[i + 1], s = arr[i + 1] < arr[i + 2], ok;
        if ((ok = (f ^ s))) res++;

        if (i == n - 3 || !ok) continue;
        int mx = max(arr[i + 1], arr[i + 2]), mn = min(arr[i + 1], arr[i + 2]);
        if (arr[i] >= mx || arr[i] <= mn) continue;
        f = mx > arr[i + 3];
        s = mn < arr[i + 3];
        if (f && s) res++;
    }
    return res;
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
        cout << solve() << '\n';
    }
    return 0;
}