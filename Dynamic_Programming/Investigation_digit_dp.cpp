#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

string a, b;
int k;
int dp[12][90][90][2][2];

int cal(int pos, int sum, int rem, bool fl, bool fr) {

    if (pos == b.size()) return sum == 0 && rem == 0;

    int &res = dp[pos][sum][rem][fl][fr];
    if (res != -1) return res;

    res = 0;
    int l = fl ? 0 : a[pos] - '0';
    int r = fr ? 9 : b[pos] - '0';

    for (int i = l; i <= r; i++) {

        res += cal(pos + 1, (sum + i) % k, (10 * rem + i) % k, 
                                    fl || i > l, fr || i < r);
    }
    return res;
}

void testcase() {

    cin >> a >> b >> k;
    a.insert(a.begin(), b.size() - a.size(), '0');
    memset(dp, -1, sizeof(dp));
    cout << cal(0, 0, 0, false, false);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)  {
        cout << "Case " << t << ": ";
        testcase();
        cout << '\n';
    }
    return 0;
}
