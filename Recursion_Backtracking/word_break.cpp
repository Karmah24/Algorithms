#include<bits/stdc++.h>
using namespace std;

unordered_set<string> dict;
vector<vector<string>> dp;
vector<string> solve(int l, string &str) {
    
    if (l == str.size()) return {""};
    if (!dp[l].empty()) return dp[l];
    
    for (int r = l; r < str.size(); r++) {
        string t = str.substr(l, r - l + 1);
        if (dict.count(t) == 0) continue;
        
        auto v = solve(r + 1, str);
        if (v[0] == " ") continue;
        for (auto &s: v) {
            dp[l].push_back(t + " " + s);
        }
    }
    if (dp[l].empty() && l != 0) dp[l] = {" "};
    return dp[l];
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    dict.clear();
    dp.assign(s.size(), vector<string>());
    for (auto &word: dictionary) dict.insert(word);
    
    return solve(0, s);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    string s;
    int n;
    cin >> s >> n;
    vector<string> dictionary(n);
    for (auto &e: dictionary) cin >> e;
    for (auto &e: wordBreak(s, dictionary)) cout << e << "\n";  
}