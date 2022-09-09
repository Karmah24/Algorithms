#include <bits/stdc++.h>
using namespace std;
#define int long long
//================================================================

vector<int> b;
int dp[20][20][2][2][2];

int cal(int pos, int back_pos, bool fr, bool fz, bool fp) {
    
    if (pos > back_pos) return fr || !fp;

    int &res = dp[pos][back_pos][fr][fz][fp];
    if (res != -1) return res;

    res = 0;
    int r = fr ? 9 : b[pos];

    for (int i = 0; i <= r; i++) {

        if (!fz && i == 0) {
            res += cal(pos + 1, back_pos, fr || i < r, fz || i, fp);
        }
        else if (i == b[back_pos]) {
            res += cal(pos + 1, back_pos - 1, fr || i < r, true, fp);
        }
        else {
            res += cal(pos + 1, back_pos - 1, fr || i < r, true, i > b[back_pos]);
        }
    }
    return res;
}

int solve(int x) {

    memset(dp, -1, sizeof(dp));
    b.clear();

    while (x) {
        b.push_back(x % 10);
        x /= 10;
    }
    reverse(b.begin(), b.end());
    if (b.empty()) b.push_back(0);

    return cal(0, b.size() - 1, false, false, false);
}
void testcase() {

    int s, e;
    cin >> s >> e;
    if (s > e) swap(s, e);

    cout << solve(e) - solve(s - 1);
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
