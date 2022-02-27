#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

bool i_bit_set(int n, int i) {
    return (n >> i) & 1;
}
int solve() {
    int n, m;
    cin >> n >> m;

    int p = m + 1, mex = 0;
    for (int i = 30; i >= 0; i--) {
        bool n_set = i_bit_set(n, i), p_set = i_bit_set(p, i);
        if (p_set == n_set) continue;
        if (p_set && !n_set) mex += 1 << i;
        else if (!p_set && n_set) return mex;
    }
    return mex;
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