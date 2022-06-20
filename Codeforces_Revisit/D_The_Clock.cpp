#include <bits/stdc++.h>
using namespace std;
//================================================================

int solve() {

    string s;
    int x;
    cin >> s >> x;

    int h = (s[0] - '0') * 10 + s[1] - '0';
    int m = (s[3] - '0') * 10 + s[4] - '0';
    int hx = x / 60, mx = x % 60;

    unordered_set<string> p;
    for (int i = 0; i < 6; i++) {
        string t = "0" + to_string(i);
        string t1 = t;
        reverse(t1.begin(), t1.end());
        p.insert(t + t1);

        t[0] = '1', t1[1] = '1';
        p.insert(t + t1);
        if (i < 4) {
            t[0] = '2', t1[1] = '2';
            p.insert(t + t1);
        }
    }
    int res = 0;
    unordered_set<string> st;

    for (int tt = 0; tt < 1440; tt++)  {

        string hs = to_string(h), ms = to_string(m);
        if (h < 10) hs = "0" + hs;
        if (m < 10) ms = "0" + ms;

        if (p.count(hs + ms)) {

            if (st.count(hs + ms)) break;
            st.insert(hs + ms);
            res++;
        }
        h = (((h + hx) % 24) + (m + mx) / 60) % 24;
        m = (m + mx) % 60;
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int T = 1;
    cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}