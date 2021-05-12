#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int>	pii;
//=======================

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        unordered_map<char, int> sMap;
        pii bounds = {0, INT_MAX};
        auto comp = [](pii a, pii b) {
            return a.second - a.first < b.second - b.first;
        };

        for (char ch: t) tMap[ch]++;
        int unique = tMap.size(), found = 0;
        int l = 0, r = 0;
        while (r < s.size()) {
            if (tMap.count(s[r]) == 0) {
                r++;
                continue;
            }
            sMap[s[r]]++;
            if (sMap[s[r]] == tMap[s[r]]) found++;

            while (found == unique) {
                bounds = min(bounds, {l, r + 1}, comp);
                if (tMap.count(s[l]) == 0) {
                    l++;
                    continue;
                }
                if (sMap[s[l]] == tMap[s[l]]) found--;
                sMap[s[l]]--;
                l++;
            }
            r++;
        }
        if (bounds.second != INT_MAX)
            return s.substr(bounds.first, bounds.second - bounds.first);
        return "";
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    Solution obj;
    string s, t;
    cin >> t >> s;
    cout << obj.minWindow(s, t);
}
