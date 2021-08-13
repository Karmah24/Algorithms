#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> dp;

    vector<string> getSentences(int l, string& str, set<string>& dict) {
        
        if (l == str.size()) return {""};
        if (!dp[l].empty()) return dp[l];

        for (int r = l; r < str.size(); r++) {
            string t = str.substr(l, r - l + 1);

            if (dict.find(t) == dict.end()) continue;

            for (string &s: getSentences(r + 1, str, dict)) {
                if (s != "") dp[l].push_back(t + " " + s);
                else dp[l].push_back(t);
            }
        }
        return dp[l];
    }
public:
    vector<string> wordBreak(vector<string>& dict, string s) {
        
        dp = vector<vector<string>>(s.size());
        set<string> dictSet(dict.begin(), dict.end());
        return getSentences(0, s, dictSet);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str;
    cin >> str;
    cin.ignore();
    vector<string> dict;
    string word;
    while (getline(cin, word, ' ')) dict.push_back(word);
    Solution obj;
    for (string s: obj.wordBreak(dict, str)) cout << s << endl;
}