#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
ll add(ll x, ll y) {return ((x % MOD) + (y % MOD)) % MOD;}
//================================================================

string a, b;
int d, k;
int dp[2005][2005][2][2];

int cal(int pos, int rem, bool fl, bool fr) {

    if (pos == b.size()) {
        return rem == 0;
    }

    int &res = dp[pos][rem][fl][fr];
    if (res != -1) return res;

    res = 0;
    int l = fl ? 0 : a[pos] - '0';
    int r = fr ? 9 : b[pos] - '0';

    if (pos % 2 == 1) {
        if ((!fl && d < l) || (!fr && d > r)) return res = 0;
        return res = cal(pos + 1, (rem * 10 + d) % k, fl || d > l, fr || d < r);
    }
    for (int dgt = l; dgt <= r; dgt++) {

        if (dgt == d) continue;
        res = add(res, cal(pos + 1, (rem * 10 + dgt) % k, fl || dgt > l, fr || dgt < r));
    }
    return res;
}

void testcase() {

    cin >> k >> d >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << cal(0, 0, false, false);
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
        testcase();
        cout << '\n';
    }
    return 0;
}
