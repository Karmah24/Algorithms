#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {
    
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int t = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        t += arr[i];
    }

    if (k <= n) {

        int s = 0, i = 0;
        while (i < k) {
            s += arr[i++];
        }
        int mx = s;
        while (i < n) {
            s += arr[i] - arr[i - k];
            mx = max(mx, s);
            i++;
        }
        return mx + (k * (k - 1)) / 2;
    }
    return n * k - ((n * (n + 1)) / 2) + t;
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