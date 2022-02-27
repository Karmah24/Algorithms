#include <bits/stdc++.h>
using namespace std;
//================================================================

bool check(string &s, string &t, string &r) {
    string res = "";
    unordered_set<char> st;
    for (auto &ch: r) {
        for (auto &c: s) {
            if (!st.count(c)) res.push_back(c);
        }
        st.insert(ch);
    }
    return res == t;
}
void solve() {
    string t;
    cin >> t;
    
    unordered_map<char, int> cnt;
    string s, r = "";
    for (int i = t.size() - 1; i >= 0; i--) {
        if (cnt[t[i]]++ == 0) r.push_back(t[i]);
    }
    reverse(r.begin(), r.end());
    bool res = true;
    for (int i = r.size() - 1; i >= 0; i--) {
        if (cnt[r[i]] % (i + 1) != 0) {
            res = false;
            break;
        }
        cnt[r[i]] /= (i + 1);
    }
    if (!res) {
        cout << "-1\n";
        return;
    }
    int uniq = cnt.size();
    for (int i = 0; i < t.size() && uniq; i++) {
        if (--cnt[t[i]] == 0) uniq--;
        s.push_back(t[i]);
    }
    if (!check(s, t, r)) cout << "-1\n";
    else cout << s << " " << r << '\n';
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
        solve();
    }
    return 0;
}