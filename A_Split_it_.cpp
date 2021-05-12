#include<bits/stdc++.h>

using namespace std;
//=======================

string solve(string str, int n, int k) {
    int l = 0, r = n - 1;
    while (k--) {
        if (str[l] != str[r]) return "NO";
        l++;
        r--;
    }
    if (r < l) return "NO";
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << solve(s, n, k) << endl;
    }
    return 0;
}