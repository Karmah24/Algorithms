#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const ll MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}
//================================================================

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
int solve() {
    
    int n, res = 0;
    cin >> n;

    int _lcm = 1;
    for (int i = 1; _lcm <= n; i++) {

        res = add(res, n / _lcm);
        _lcm = lcm(_lcm, i + 1);
    }
    return add(res, n);
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