#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<string> sorted(strs.begin(), strs.end());
        for (string& s: sorted) sort(s.begin(), s.end());

        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {

            map[sorted[i]].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto e: map) {
            res.push_back(e.second);
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
