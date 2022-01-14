#include <bits/stdc++.h>
using namespace std;

class Solution {
    void getPerms(vector<string>& arr, int i, set<vector<string>>& perms) {

        if (i == arr.size() - 1) {
            perms.insert(arr);
            return;
        }
        for (int j = i; j < arr.size(); j++) {
            swap(arr[i], arr[j]);
            getPerms(arr, i + 1, perms);
            swap(arr[i], arr[j]);
        }
    }
public:
    vector<int> findSubstring1(string str, vector<string>& words) {

        set<vector<string>> perms;
        getPerms(words, 0, perms);

        vector<int> res;
        for (auto v: perms) {
            string s = "";
            for (string t: v) s += t;

            size_t found = str.find(s);
            while (found != string::npos) {
                res.push_back(static_cast<int>(found));
                found = str.find(s, found + 1);
            }
        }
        return res;
    }
    // all words have equal lengths
    vector<int> findSubstring(string str, vector<string>& words) {

        int n = str.size(), x = words.size(), l = words[0].size();
        unordered_map<string, int> wMap, sMap;
        for (string s: words) wMap[s]++;

        vector<int> res;
        for (int i = 0; i < n; i++) {
            sMap = wMap;
            int j = i;
            string word;
            while (j + l <= n) {
                word = str.substr(j, l);
                if (sMap.find(word) == sMap.end()) break;
                if (--sMap[word] == 0) sMap.erase(word);
                j += l;
            }
            if (sMap.empty()) res.push_back(i);
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string str;
    cin >> str;
    cin.ignore();
    vector<string> words;
    string word;
    while (getline(cin, word, ' ')) words.push_back(word);
    Solution obj;
    for (int e: obj.findSubstring(str, words)) cout << e << " ";
}