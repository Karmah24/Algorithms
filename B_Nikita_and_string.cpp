#include <bits/stdc++.h>
using namespace std;

int solve() {
    
    string str;
    cin >> str;
    vector<int> res(str.size());
    int a = 0, b = 0, a1 = 0, b1 = 0;
    for (int i = 0; i < str.size(); i++) {

        if (str[i] == 'a') {
            b1 = 0;
            res[i] = max(++a, b + (++a1));
        }
        else {
            a1 = 0;
            res[i] = max(++b, a + (++b1));
        }
    }
    a = 0;
    int ans = 0;
    for (int i = str.size() - 1; i >= 0; i--) {

        if (str[i] == 'b') res[i] += a;
        else a++;
        ans = max(ans, res[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed);

    int T = 1;
    // cin >> T;
    while (T--) {
        cout << solve();
    }
    return 0;
}