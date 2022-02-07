#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================
int n, k;
int check(int len, vector<int> &pfx) {
    for (int x = 1; x <= n - len + 1; x++) {
        if (pfx[x + len - 1] - pfx[x - 1] >= (n + k + 1) / 2) return x;
    }
    return -1;
}
void solve() {
    cin >> n >> k;
    vector<int> arr(n), cnt(n + 1), pfx(n + 1);
    for (auto &e: arr) {
        cin >> e;
        cnt[e]++;
    }
    // pfx[0] = 0;
    // pfx[1] = cnt[1];
    // for (int i = 2; i <= n; i++) {
    //     pfx[i] = pfx[i - 1] + cnt[i];
    // }
    // int lo = 1, hi = n, x, y;
    // while (lo <= hi) {
    //     int len = (lo + hi) / 2;
    //     int res = check(len, pfx);
    //     if (res != -1) {
    //         x = res;
    //         y = x + len - 1;
    //         hi = len - 1;
    //     }
    //     else lo = len + 1;
    // }
    int x = 1, y = n + 1, j = 1, sum = -n;
    for (int i = 1; i <= n; i++) {
        while (j <= n) {
            if (sum >= k) break;
            sum += 2 * cnt[j++];
        }
        if (sum >= k) {
            if (y - x > j - i) {
                y = j, x = i;
            }
        }
        else break;
        sum -= 2 * cnt[i];
    }
    --y;
    cout << x << " " << y << '\n';
    int p = 0, r = 1;
    for (int i = 0; i < n && k > 1; i++)  {
        if (arr[i] >= x && arr[i] <= y) p++;
        else p--;
        if (p > 0) {
            cout << r << " " << i + 1 << '\n';
            r = i + 2;
            p = 0;
            k--;
        }
    }
    cout << r << " " << n << '\n';
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
        solve();
    }
    return 0;
}