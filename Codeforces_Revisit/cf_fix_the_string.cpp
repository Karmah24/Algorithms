#include <bits/stdc++.h>
using namespace std;
// #define int long long
//================================================================

int diff(string &s, string s1, int i) {
    int d = 0;
    for (int j = 0; j < s1.size(); j++) {
        if (s[i + j] != s1[j]) d++;
    }
    return d;
}
int solve() {
    int n, x, res = 0;
    string s;
    cin >> n >> s;
    vector<int> a(n - 3);
    int prev = -4;
    for (int i = 0; i < n - 3; i++) {
        cin >> a[i];
        if (a[i] == 0) continue;
        if (i - prev == 3 || i - prev == 1) res = -1;
    }
    if (res == -1) return res;
    int i = 1;
    while (i < a.size()) {
        if (a[i] == 0) {
            i++;
            continue;
        }
        int j = i;
        while (j < a.size() && a[j + 2] == 1) j += 2;
        if (i == j) {
            res += min(diff(s, "(())", i), diff(s, "()()", i));
        }
        else {
            for (int k = i; k < j + 4; k += 2) res += diff(s, "()", k);
        }
        i = j + 1;
    }
    return res;
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
        cout << solve() << '\n';
    }
    return 0;
}