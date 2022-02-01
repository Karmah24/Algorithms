#include <bits/stdc++.h>
using namespace std;
#define ll long long
//=======================

ll setBitCnt(int N, int k) { // numbers <= N with kth bit set

    ll res = (N >> (k + 1)) << k;
    if (N & (1 << k)) res += N & ((1ll << k) - 1);
    return res;
}
ll solve() {

    int l, r;
    cin >> l >> r;
    ll res = 0;
    for (int i = 0; i < 19; i++) {
        res = max(res, setBitCnt(r + 1, i) - setBitCnt(l, i));
    }
    return r - l + 1 - res;
}
int main() {
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