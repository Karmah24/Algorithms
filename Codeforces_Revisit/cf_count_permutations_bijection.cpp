#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
const ll MOD = 1e9 + 7;
ll mul(ll x, ll y) {return ((x % MOD) * (y % MOD)) % MOD;}
//=======================

int solve() {

    int n;
    cin >> n;
    ll res = 1;
    // implicit division by 2
    for (int i = 3; i <= 2 * n; i++) res = mul(res, i);
    return res;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) {

        cout << solve() << ln;
    }
    return 0;
}