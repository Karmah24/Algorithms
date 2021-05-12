#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
//=======================

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted(all(strs));
        for (string& s: sorted) sortall(s);

        unordered_map<string, vector<string>> map;
        fori (i, strs.size()) {
            if (map.find(sorted[i]) == map.end()) 
                map.insert({sorted[i], vector<string>{strs[i]}});

            else map[sorted[i]].push_back(strs[i]);
        }
        int i = 0;
        vector<vector<string>> res;
        for (auto e: map) {
            res.push_back(vector<string>());
            for (string s: e.second) res[i].push_back(s);
            i++;
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    vector<string> strs;
    string token;
    while (getline(cin, token, ' ')) strs.push_back(token);
    Solution obj;
    for (auto e: obj.groupAnagrams(strs)) {
            for (auto s: e) cout << s << ' ';
            cout << endl;
    }
}
