#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue<int, vector<int>, greater<int>> pq;
    int health = 0;
    for (int i = 0; i < n; i++) {
        health += a[i];
        pq.push(a[i]);
        if (health < 0) {
            health -= pq.top();
            pq.pop();
        }
    }
    return pq.size();
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}