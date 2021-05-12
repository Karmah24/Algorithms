#include <bits/stdc++.h>
using namespace std;

#define fori(i, n) for (int i = 0; i < n; i++)
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
public:
    vector<pair<int, int>> getNeighbours(int i, int j, vector<vector<char>> board) {
        vector<pair<int, int>> neighbours;
        for (int r = i - 1; r <= i + 1; r++) {
            for (int c = j - 1; c <= j + 1; c++) {
                if (r >= 0 && j >= 0 && r < board.size() && c < board[0].size())
                    neighbours.push_back({r, c});
            }
        }
        return neighbours;
    }
    void explore(int i, int j, vector<vector<char>> board, TrieNode* node, vector<vector<bool>>& vis,
        unordered_set<string>& finalWords) {
            if (vis[i][j]) return;
            char c = board[i][j];
            if (node->map.find(c) == node->map.end()) return;
            vis[i][j] = true;
            node = node->map[c];
            if (node->endWord != "") finalWords.insert(node->endWord);
            vector<pair<int, int>> neighbours = getNeighbours(i, j, board);
            for (auto neighbour: neighbours)
                explore(neighbour.first, neighbour.second, board, node, vis, finalWords);
            vis[i][j] = false;
        }

    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        Trie trie;
        for (string word: dictionary) trie.insert(word);
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        unordered_set<string> finalList;
        fori (i, board.size())
            fori (j, board[0].size()) explore(i, j, board, trie.root, vis, finalList);
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
    fori (i, n) cin >> dictionary[i];
    int R, C;
    cin >> R >> C;
    vector<vector<char>> board(R, vector<char>(C));
    fori  (r, R) fori (c, C) cin >> board[r][c]; 
    auto start = chrono::high_resolution_clock::now();
    Solution obj;
    for (string s: obj.wordBoggle(board, dictionary))
        cout << s << ' ';

    auto stop = chrono::high_resolution_clock::now();
    cout << endl << chrono::duration_cast<chrono::milliseconds>(stop - start).count();
}
