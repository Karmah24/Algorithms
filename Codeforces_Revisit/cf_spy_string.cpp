#include <bits/stdc++.h>
using namespace std;
//================================================================

string solve() {
    int n, m;
    cin >> n >> m;
    string str, temp;

    unordered_map<string, int> mp;
    unordered_set<string> st;
    for (int i = 0; i < n; i++) {
        cin >> str;
        st.clear();
        for (int j = 0; j < m; j++) {
            temp = str;
            for (char c = 'a'; c <= 'z'; c++) {
                temp[j] = c;
                st.insert(temp);
            }
        }
        for (auto &s: st) mp[s]++;
    }
    for (auto &[k, v]: mp) if (v == n) return k;
    return "-1";
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