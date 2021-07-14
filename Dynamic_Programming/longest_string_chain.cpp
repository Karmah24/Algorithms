#include <bits/stdc++.h>
using namespace std;


class Solution {
    int solve(string str, unordered_map<string, int>& chain, unordered_set<string>& vis) {
        
        if (vis.find(str) != vis.end()) return chain[str];
        int longest = 1, n = str.size();
        for (int i = 0; i < n; i++) {
            string next = str.substr(0, i) + str.substr(i + 1, n);
            if (chain.find(next) == chain.end()) continue;
            longest = max(longest, solve(next, chain, vis) + 1);
        }
        chain[str] = longest;
        vis.insert(str);
        return longest;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> chain;
        unordered_set<string> vis;
        for (int i = 0; i < n; i++) chain.insert({words[i], 1});
        int longest = 0;
        for (int i = 0; i < n; i++) {
            if (vis.find(words[i]) != vis.end()) continue;
            longest = max(longest, solve(words[i], chain, vis));
        }
        return longest;
    }
};

class Solution1 {
    int solve(string str, unordered_map<string, int>& chain) {
        int longest = 1, n = str.size();
        for (int i = 0; i < n; i++) {
            string next = str.substr(0, i) + str.substr(i + 1, n);
            if (chain.find(next) == chain.end()) continue;
            longest = max(longest, chain[next] + 1);
        }
        chain[str] = longest;
        return longest;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> chain;
        for (int i = 0; i < n; i++) chain.insert({words[i], 1});

        auto comp = [](string a, string b) {
            return (a.size() < b.size());
        };
        sort(words.begin(), words.end(), comp);
        int longest = 0;
        for (int i = 1; i < n; i++) {
            longest = max(longest, solve(words[i], chain));
        }
        return longest;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    vector<string> in;
    string s;
    while (getline(cin, s, ' ')) in.push_back(s);
    Solution1 obj;
    cout << obj.longestStrChain(in);
}