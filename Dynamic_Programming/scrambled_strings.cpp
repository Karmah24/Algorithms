#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, bool> mp;

    bool solve(string s1, string s2) {

        if (s1 == s2) return true;
        int n = s1.size();
        if (n == 1) return false;
        if (mp.find(s1 + s2) != mp.end()) return mp[s1 + s2];

        bool res;
        for (int i = 1; i < n; i++) {

            res = solve(s1.substr(0, i), s2.substr(n - i, i)) && solve(s1.substr(i, n - i), s2.substr(0, n - i));
            if (res) break;
            res = solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n - i), s2.substr(i, n - i));
            if (res) break;
        }
        return mp[s1 + s2] = res;
    }
public:
    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size()) return false;
        mp = unordered_map<string, bool>();
        return solve(s1, s2);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s1, s2;
    cin >> s1 >> s2;
    Solution obj;
    cout << obj.isScramble(s1, s2);
}