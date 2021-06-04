#include <bits/stdc++.h>
using namespace std;

class Solution {

    int dp[300];

    bool solve(string& str, int l, unordered_set<string>& s) {
        
        if (dp[l] != -1) return dp[l];
        if (l == str.size()) return true;

        dp[l] = 0;

        for (int r = l + 1; r <= str.size(); r++) {
            if (s.count(str.substr(l, r - l)) != 0 && solve(str, r, s)) {
                dp[l] = 1;
                break;
            }
        }
        return dp[l];
    }
public:
    bool wordBreak(string str, vector<string>& wordDict) {

        unordered_set<string> s;
        for (string str: wordDict) s.insert(str);
        memset(dp, -1, sizeof(dp));

        return solve(str, 0, s);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str, in;
    vector<string> wordDict;
    cin >> str;
    cin.ignore();
    while (getline(cin, in, ' ')) wordDict.push_back(in);
    Solution obj;
    cout << obj.wordBreak(str, wordDict);
}
