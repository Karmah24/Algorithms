#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

int k, n;
vector<int> digits;
int dp[12][12];

int cal(int pos, int prev) { 

    if (pos == n + 1) return 1;

    int &res = dp[pos][prev + 1];
    if (res != -1) return res;

    res = 0;

    for (auto &d: digits)  {

        if (abs(d - prev) <= 2 || prev == -1) {
            res += cal(pos + 1, d);
        }
    }
    return res;
}

void testcase() {

    cin >> k >> n;
    digits.resize(k);
    for (auto &d: digits) cin >> d;
    memset(dp, -1, sizeof(dp));
    cout << cal(1, -1);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif
    int T = 1, t = 1;
    cin >> T;
    while (T--) {
        cout << "Case " << t++ << ": ";
        testcase();
        cout << '\n';
    }
    return 0;
}
