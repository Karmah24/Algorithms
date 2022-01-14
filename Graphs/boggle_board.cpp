#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
//=======================

struct TrieNode {
    unordered_map<char, TrieNode*> map;
    string endWord = "";
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
        curr->endWord = word;
    }
};

class Solution {
    unordered_map<char, vector<pair<int, int>>> map;
    
    bool adjacent(pair<int, int> a, pair<int, int> b) {
        if (max(abs(a.first - b.first), abs(a.second - b.second)) <= 1) return true;
        return false;
    }
    void find (TrieNode* node, pair<int, int> pos, vector<vector<char>>& board, 
        vector<vector<bool>> vis, unordered_set<string>& finalList) {
            if (node->endWord != "") {
                finalList.insert(node->endWord);
            }
            vis[pos.first][pos.second] = true;

            for (auto next_node: node->map) {
                for (auto next: map[next_node.first]) {
                    if (vis[next.first][next.second] || !adjacent(pos, next))
                        continue;
                    find(next_node.second, next, board, vis, finalList);
                }
            }
            vis[pos.first][pos.second] = false;
        }
public:
    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        int n = board.size(), m = board[0].size();
        loop (i, n) loop (j, m) map[board[i][j]].push_back({i, j});

        Trie trie;
        for (string word: dictionary) trie.insert(word);

        unordered_set<string> finalList;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (auto node: trie.root->map) {
            for (auto pos: map[node.first]) {
                find(node.second, pos, board, vis, finalList);
            }
        }
        return vector<string>(finalList.begin(), finalList.end());
    }
};

class Solution1 {
    unordered_map<char, vector<pair<int, int>>> map;
    
    bool adjacent(pair<int, int> a, pair<int, int> b) {
        if (max(abs(a.first - b.first), abs(a.second - b.second)) <= 1) return true;
        return false;
    }
    
    bool find(string word, pair<int, int> pos, int index, vector<vector<char>>& board, 
        vector<vector<bool>>& vis) {

        if (index == word.size()) return true;
        vis[pos.first][pos.second] = true;
        for (auto next: map[word[index]]) {

            if (vis[next.first][next.second] || !adjacent(pos, next)
                || !find(word, next, index + 1, board, vis)) 
                continue;
            
            vis[pos.first][pos.second] = false;
            return true;
        }
        vis[pos.first][pos.second] = false;
        return false;
    }
public:
    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        int n = board.size(), m = board[0].size();
        loop (i, n) loop (j, m) map[board[i][j]].push_back({i, j});

        unordered_set<string> finalList;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (string word: dictionary) {
            for (auto pos: map[word[0]]) {
                vis[pos.first][pos.second] = true;
                if (find(word, pos, 1, board, vis)) {
                    vis[pos.first][pos.second] = false;
                    finalList.insert(word);
                    break;
                }
                vis[pos.first][pos.second] = false;
            }
        }
        return vector<string>(finalList.begin(), finalList.end());
    }
};
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<string> dictionary(n);
    loop (i, n) cin >> dictionary[i];
    int R, C;
    cin >> R >> C;
    vector<vector<char>> board(R, vector<char>(C));
    loop  (r, R) loop (c, C) cin >> board[r][c]; 
    auto start = chrono::high_resolution_clock::now();
    Solution obj;
    for (string s: obj.wordBoggle(board, dictionary))
        cout << s << ' ';
    
    auto end = chrono::high_resolution_clock::now();
    cout << endl << chrono::duration_cast<chrono::milliseconds>(end - start).count();
}