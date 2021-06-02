#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> map;
    int stPt = 0;
    bool isEnd = false;
};
void insert(string str, TrieNode *root) {
    
    TrieNode *curr = root;
    for (char ch: str) {
        
        if (curr->map.find(ch) == curr->map.end()) curr->map[ch] = new TrieNode();
        curr->stPt++;
        curr = curr->map[ch];

    }
    curr->isEnd = true;
}

string search(string str, TrieNode *root) {

    TrieNode *curr = root;
    string prefix = "";
    int i = 0;
    
    while (curr->stPt > 1 && !curr->isEnd) {
        
        prefix.push_back(str[i]);
        curr = curr->map[str[i++]];
    }
    return prefix;
}

class Solution {
public:
    vector<string> prefix(vector<string> &A) {
        
        TrieNode *root = new TrieNode();
        for (string s: A) insert(s, root);
        
        vector<string> res;
        
        for (string s: A) {
            res.push_back(search(s, root));
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    Solution obj;
    for (string s: obj.prefix(A)) cout << s << " ";
}