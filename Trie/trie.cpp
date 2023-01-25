#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* arr[2] = {nullptr};
	int cnt[2] = {0};
};

class Trie {
public:
	Node *root = nullptr;
	void insert(int n) {
		if (!root) root = new Node();
		Node *u = root;
		for (int i = 30; i >= 0; i--) {
			int x = (n >> i) & 1;
			u->cnt[x]++;
			if (!u->arr[x]) u->arr[x] = new Node();
			u = u->arr[x];
		}
	}
	void remove(int n) {
		Node *u = root;
		for (int i = 30; i >= 0 && u; i--) {
			int x = (n >> i) & 1;
			if (--u->cnt[x] == 0) u->arr[x] = nullptr;
			u = u->arr[x];
		}
	}
	int dfs(int n, int i) {
		int res = 0;
        Node *u = root;
        for (int i = 30; i >= 0; i--) {
            int x = (n >> i) & 1;
            if (u->arr[1 - x]) {
                res |= (1 << i);
                u = u->arr[1 - x];
            }
            else u = u->arr[x];
        }
        return res;
	}
};

struct TrieNode {
    unordered_map<char, TrieNode*> mp;
    bool isEnd = false;
};
class Trie {
public:
    TrieNode* root = nullptr;
    void insert(string word) {
        if (!root) root = new TrieNode();
        TrieNode* curr = root;
        for (char c: word) {
            if (curr->mp.find(c) == curr->mp.end()) curr->mp[c] = new TrieNode();
            curr = curr->mp[c];
        }
        curr->isEnd = true;
    }
    bool search(string word) {
        if (!root) return false;
        TrieNode* curr = root;
        for (char c: word) {
            curr = curr->mp[c];
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
