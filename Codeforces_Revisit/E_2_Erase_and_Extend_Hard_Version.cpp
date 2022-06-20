#include <bits/stdc++.h>
using namespace std;
//================================================================

string solve() {

    int n, k;
    string str, res = "";
    cin >> n >> k >> str;

    int r = 1;
    while (r < n && str[r] <= str[0]) r++;

    int i = 1;
    while (i < r) {

        if (str[i] < str[0]) {
            i++;
            continue;
        }
        int j = 1, k = i + 1;
        while (k < r && str[j] == str[k]) j++, k++;
        if (k == r || str[j] < str[k]) break;
        else {
            i = k;
            continue;
        }
    }
    res = string(str.begin(), str.begin() + i);
    while (res.size() < k) res += res;
    while (res.size() > k) res.pop_back();
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int T = 1;
    // cin >> T;
    while (T--) {
        cout << solve() << '\n';
    }
    return 0;
}