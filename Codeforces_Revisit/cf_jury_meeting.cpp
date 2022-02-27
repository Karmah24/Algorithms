#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll MOD = 998244353;
ll mul(ll x, ll y) {return ((x % MOD) * (y % MOD)) % MOD;}
ll sub(ll x, ll y) {return ((x % MOD) - (y % MOD) + MOD) % MOD;}
//================================================================

int solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &e: arr) cin >> e;
    
    int mx = *max_element(arr.begin(), arr.end());
    int cnt_mx = count(arr.begin(), arr.end(), mx);
    int k = count(arr.begin(), arr.end(), mx - 1);
    int tot_perm = 1, bad_perm = 1;
    for (int i = 2; i <= n; i++) {
        tot_perm = mul(tot_perm, i);
        if (i != k + 1) bad_perm = mul(bad_perm, i);
    }
    if (cnt_mx > 1) return tot_perm;
    return sub(tot_perm, bad_perm);
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