#include <bits/stdc++.h>
using namespace std;
// #define int long long
//=======================

int solve() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    // queue<int> q;
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    //     if (arr[i] == 0) q.push(i);
    // }
    // int left = n - q.size(), res = 0;
    // while (!q.empty() && left) {
    //     res++;
    //     int sz = q.size();
    //     while (sz--) {
    //         int u = q.front();
    //         q.pop();
    //         int v = (u + n - d) % n;
    //         if (arr[v] == 0) continue;
    //         arr[v] = 0;
    //         q.push(v);
    //         left--;
    //     }
    // }
    // if (left) return -1;
    // return res;
    int g = gcd(n, d);
    int g_sz = n / g;
    vector<vector<int>> grps(g);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < g; i++) {
        for (int j = 0, p = i; j < 2 * g_sz; j++, p = (p + d) % n) {
            grps[i].push_back(arr[p]);
        }
    }
    int res = 0;
    for (auto &grp: grps) {
        int curr = 0, x = 0;
        for (auto &e: grp) {
            if (e == 1) x++;
            else {
                curr = max(curr, x);
                x = 0;
            }
        }
        curr = max(curr, x);
        if (curr == 2 * g_sz) return -1;
        res = max(res, curr);
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