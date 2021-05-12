#include <bits/stdc++.h>
using namespace std;

class Solution {

    int dp[300];

    bool solve(string& s, int l, unordered_set<string>& set) {
        
        if (dp[l] != -1) return dp[l];
        if (l == s.size()) return true;

        dp[l] = 0;

        for (int r = l + 1; r <= s.size(); r++) {

            if (set.count(s.substr(l, r - l)) != 0 && solve(s, r, set)) {
                dp[l] = 1;
                break;
            }
        }
        return dp[l];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> set;
        for (string str: wordDict) set.insert(str);
        memset(dp, -1, sizeof dp);

        return solve(s, 0, set);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s, in;
    vector<string> wordDict;
    cin >> s;
    cin.ignore();
    while (getline(cin, in, ' ')) wordDict.push_back(in);
    Solution obj;
    cout << obj.wordBreak(s, wordDict);
}
