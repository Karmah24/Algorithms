#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {

    int n, k;
    cin >> n >> k;
    vector<int> rem(k, 0);

    int res = 0, ai;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        res += ai / k;
        rem[ai % k]++;
    }
    int i = 1, j = k - 1;
    while (i < j) {
        int mn = min(rem[i], rem[j]);
        res += mn;
        rem[i] -= mn, rem[j] -= mn;
        if (rem[j] == 0) {
            j--;
            if (i + j < k) i++;
        }
        else i++;
    }
    if (i < k) res += rem[i] / 2;
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}