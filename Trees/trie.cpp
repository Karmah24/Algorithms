#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> map;
    bool isEnd = false;
};
class Trie {
public:
    TrieNode* root = nullptr;
    void insert(string word) {
        if (!root) root = new TrieNode();
        TrieNode* curr = root;
        for (char c: word) {
            if (curr->map.find(c) == curr->map.end()) curr->map[c] = new TrieNode;
            curr = curr->map[c];
        }
        curr->isEnd = true;
    }
    bool search(string word) {
        if (!root) return false;
        TrieNode* curr = root;
        for (char c: word) {
            curr = curr->map[c];
            if (!curr) return false;
        }
        return curr->isEnd;
    }
};

class Solution {
public:
    void solve() {
        Trie trie;
        vector<string> dictionary, wordList;
        string word, input;
        getline(cin, input); istringstream dic(input);
        while (getline(dic, word, ' ')) dictionary.push_back(word);

        getline(cin, input); istringstream wl(input);
        while (getline(wl, word, ' ')) wordList.push_back(word);
        
        for (string word: dictionary) trie.insert(word);
        int present = 0;
        for (string word: wordList) if (trie.search(word)) present++;
        cout << present << endl;
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Solution obj;
    obj.solve();
}
