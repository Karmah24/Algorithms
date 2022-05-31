#include <bits/stdc++.h>
using namespace std;
//================================================================

const int M = 32768;
vector<int> res(M + 1, -1);

int dfs(int u) {
    if (res[u] != -1) return res[u];

    res[u] = dfs((u * 2) % M) + 1;
    res[u] = min(res[u], dfs((u + 1) % M) + 1);
    return res[u];
}
int solve() {
    int x;
    cin >> x;
    return dfs(x);
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    res[0] = 0;
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << ' ';
    }
    return 0;
}