#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

string a, b;
int dp[20][180][2][2];

int cal(int pos, int sum, bool fl, bool fr) {

    if (pos == b.size()) return sum;

    int &res = dp[pos][sum][fl][fr];
    if (res != -1) return res;

    res = 0;
    int l = fl ? 0 : a[pos] - '0';
    int r = fr ? 9 : b[pos] - '0';

    for (int i = l; i <= r; i++) {

        res += cal(pos + 1, sum + i, fl || i > l, fr || i < r);
    }
    return res;
}

void testcase() {

    cin >> a >> b;
    a.insert(a.begin(), b.size() - a.size(), '0');
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
    cin >> T;
    while (T--) {
        testcase();
        cout << '\n';
    }
    return 0;
}
