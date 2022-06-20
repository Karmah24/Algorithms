#include <bits/stdc++.h>
using namespace std;
//================================================================

int solve() {

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<bool> vis(n, false);
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        vector<int> tmp;
        int x = i;
        while (x < n) {
            vis[x] = true;
            tmp.push_back(arr[x]);
            x += k;
        }
        sort(tmp.begin(), tmp.end());
        int j = 0;
        x = i;
        while (x < n) {
            res[x] = tmp[j++];
            x += k;
        }
    }
    cout << '\n';
    for (int i = 0; i < n - 1; i++) {
        if (res[i] > res[i + 1]) return false;
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        if (solve()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}